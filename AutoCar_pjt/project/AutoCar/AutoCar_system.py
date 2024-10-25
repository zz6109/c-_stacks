
__version__='1.2.1'

''' Pop AutoCar '''
import time
import math
import smbus2 as smbus
import random
import __main__
import subprocess as sp

if not "pwm_time_log" in dir(__main__):
    __main__.pwm_time_log = 0

class PWM(object):
    _mode_adr              = 0x00  # Mode 1 Reg
    _base_adr_low          = 0x08 
    _base_adr_high         = 0x09
    _prescale_adr          = 0xFE  # Prescale Reg

    def __init__(self, bus, address, wait_i2c=True):
        '''
        I2C 버스에 연결된 PWM 컨트롤러 인스턴스 생성
        @param bus: PWM 컨트롤러가 연결된 I2C 버스 번호(0, 1).
        @param address: PWM 컨트롤러 주소(기본값은 0x41)
        '''
        self.wait_i2c=wait_i2c
        self.bus = smbus.SMBus(bus)
        self.address = address
        self._writeByte(self._mode_adr, 0x00)

    def setFreq(self, freq):
        '''
        PWM 주파수 설정
        @param freq: Hz 단위 주파수
        '''
        prescaleValue = 25000000.0    # 25MHz
        prescaleValue /= 4096.0       # 12-bit
        prescaleValue /= float(freq)
        #prescaleValue -= 1.0
        prescale = math.floor(prescaleValue + 0.5)
        if prescale < 3:
            raise ValueError("주파수 설정 오류")

        oldmode = self._readByte(self._mode_adr)
        newmode = (oldmode & 0x7F) | 0x10 # mode 1, sleep
        self._writeByte(self._mode_adr, newmode)
        self._writeByte(self._prescale_adr, int(math.floor(prescale)))
        self._writeByte(self._mode_adr, oldmode)
        time.sleep(0.005)
        self._writeByte(self._mode_adr, oldmode | 0xA1) #mode 1, autoincrement on (old 0x80)

    def setDuty(self, channel, duty):
        '''
        PWM 채널의 듀티비 설정
        @param channel: 채널 번호 (0~15)
        @param duty: 튜티비 (0~100)
        '''
        data = int(duty * 4096 / 100) # 0..4096 (included)
        
        if self.wait_i2c:
            while time.time()-__main__.pwm_time_log<0.05: time.sleep(0.01)
        self._writeByte(self._base_adr_low + 4 * channel, data & 0xFF)
        self._writeByte(self._base_adr_high + 4 * channel, data >> 8)
        __main__.pwm_time_log=time.time()

    def _writeByte(self, reg, value):
        try:
            self.bus.write_byte_data(self.address, reg, value)
        except Exception as e:
            v=ValueError("[Errno "+str(e.errno)+"] An error occured while reading I2C Devcie")
            v.errno=e.errno
            raise v

    def _readByte(self, reg):
        try:
            result = self.bus.read_byte_data(self.address, reg)
            return result
        except Exception as e:
            v=ValueError("[Errno "+str(e.errno)+"] An error occured while reading I2C Devcie")
            v.errno=e.errno
            raise v


'''
0 : AutoCar
1 : AutoCar Racing
2 : SerBot
3 : AutoCar Prime
4 : SerBot Prime X
5 : AutoCar Prime X
6 : AutoCar Prime + NX
'''
_cat = 0

try :
    _p=PWM(0,0x5d) #AutoCar
    __main__._camera_flip_method='0'
except Exception as e:
    if e.errno == 121:
        try :
            _p=PWM(0,0x40) #SerBot
            __main__._camera_flip_method='2'
            _cat = 2
        except Exception as e:
            if e.errno == 121:
                try :
                    _p=PWM(0,0x5c) #AutoCar Prime
                    __main__._camera_flip_method='0'
                    _cat = 3
                except:
                    try:
                        _p=PWM(1,0x5c) #AutoCar Prime + NX
                        __main__._camera_flip_method='0'
                        _cat = 6
                    except Exception as e:
                        if e.errno == 121:
                            try:
                                import can
                                __c=can.interface.Bus(channel='can0', bustype='socketcan_native')
                                __c.send(can.Message(arbitration_id=0x100,is_extended_id=False,data=None))
                                __splitter=__c.recv(timeout=2).data[0]

                                if __splitter==1: #AutoCar Prime X
                                    _cat = 5
                                    __main__._camera_flip_method='0'
                                elif __splitter==2: #SerBot Prime X
                                    _cat = 4
                                    __main__._camera_flip_method='2'
                                else:
                                    _cat = 4 #Default : SerBot Prime X
                                    __main__._camera_flip_method='2'
                                __c=None
                            except Exception as e:
                                if e.errno==19:
                                    _cat = 1 #AutoCar Racing
                                    __main__._camera_flip_method='0'

_p=None

has_lidar="10c4:ea60" in str(sp.check_output(["lsusb"], shell=True))


class Driving:
    '''
    t       duty cycle          speed
    0.72ms   0.72ms/20ms = 3.6%   0 degs
    1.36ms   1.36ms/20ms = 6.8%   0
    2.0ms   2.0ms/20ms = 10%  100%
    '''

    GPIO_ESC = 12

    GPIO_LEFT_FORWARD    = 0
    GPIO_LEFT_BACKWARD   = 1
    GPIO_RIGHT_FORWARD   = 2
    GPIO_RIGHT_BACKWARD  = 3

    MIN_SPEED = 20
    MAX_SPEED = 99

    STD_DUTY=7.4 #6.8
    DUTY_RANGE=1.2 #If you want to set the maximum performance speed of the motor, replace it to 3.2.

    STAT_STOP = 1
    STAT_FORWARD = 2
    STAT_BACKWARD = 3

    stat=1

    def __init__(self, bus, addr, freq):
        if _cat==0 or _cat==1 or _cat==3 or _cat==6:
            self.stat = Driving.STAT_STOP
            self.pwm = PWM(bus, addr)
            self.pwm.setFreq(freq)
            self.speed = Driving.MIN_SPEED
        elif _cat==5:
            global CAN
            from AutoCar_system import CAN
            self._can=CAN.Car()

    def __del__(self):
        if _cat==1:
            self.pwm.setDuty(Driving.GPIO_ESC, Driving.STD_DUTY)
        elif _cat==0 or _cat==3 or _cat==6:
            self.pwm.setDuty(Driving.GPIO_RIGHT_FORWARD, 0)
            self.pwm.setDuty(Driving.GPIO_LEFT_FORWARD, 0)
            self.pwm.setDuty(Driving.GPIO_RIGHT_BACKWARD, 0)
            self.pwm.setDuty(Driving.GPIO_LEFT_BACKWARD, 0)
        elif _cat==5:
            self._can.wheel(0)
            self._can.camPan(0)
            self._can.camTilt(0)
            self._can.steer(0)

    def setSpeed(self, speed):
        if self.stat != Driving.STAT_STOP:
            self.direction(self.stat, speed)

    def getSpeed(self):
        return self.speed

    def stop(self):
        if _cat==1:
            self.pwm.setDuty(Driving.GPIO_ESC, Driving.STD_DUTY)
        elif _cat==0 or _cat==3 or _cat==6:
            self.pwm.setDuty(Driving.GPIO_RIGHT_BACKWARD, 0)
            self.pwm.setDuty(Driving.GPIO_LEFT_FORWARD, 0)
            self.pwm.setDuty(Driving.GPIO_RIGHT_FORWARD, 0)
            self.pwm.setDuty(Driving.GPIO_LEFT_BACKWARD, 0)
        elif _cat==5:
            self._can.wheel(0)

        self.stat = Driving.STAT_STOP

    def direction(self, stat, speed):
        if speed:
            if speed > Driving.MAX_SPEED:
                speed = Driving.MAX_SPEED
            elif speed < Driving.MIN_SPEED:
                speed = Driving.MIN_SPEED
            self.speed = speed

        if _cat==1:
            speed_rate = speed/Driving.MAX_SPEED
            speed_duty = (speed_rate * Driving.DUTY_RANGE)

            if stat == Driving.STAT_BACKWARD:
                duty = Driving.STD_DUTY - speed_duty
                if self.stat != Driving.STAT_BACKWARD:
                    self.pwm.setDuty(Driving.GPIO_ESC, duty)
                    self.pwm.setDuty(Driving.GPIO_ESC, Driving.STD_DUTY)
                    self.pwm.setDuty(Driving.GPIO_ESC, duty)
                else:
                    self.pwm.setDuty(Driving.GPIO_ESC, duty)

                self.stat = Driving.STAT_BACKWARD
            else:
                duty = Driving.STD_DUTY + speed_duty
                self.stat = Driving.STAT_FORWARD
                self.pwm.setDuty(Driving.GPIO_ESC, duty)
        elif _cat==0 or _cat==3 or _cat==6:
            if stat == Driving.STAT_BACKWARD:
                self.stat = Driving.STAT_BACKWARD
                self.pwm.setDuty(Driving.GPIO_RIGHT_BACKWARD, 0)
                self.pwm.setDuty(Driving.GPIO_LEFT_FORWARD, 0)
                self.pwm.setDuty(Driving.GPIO_RIGHT_FORWARD, self.speed)
                self.pwm.setDuty(Driving.GPIO_LEFT_BACKWARD, self.speed)
            else:
                self.stat = Driving.STAT_FORWARD
                self.pwm.setDuty(Driving.GPIO_RIGHT_FORWARD, 0)
                self.pwm.setDuty(Driving.GPIO_LEFT_BACKWARD, 0)
                self.pwm.setDuty(Driving.GPIO_RIGHT_BACKWARD, self.speed)
                self.pwm.setDuty(Driving.GPIO_LEFT_FORWARD, self.speed)
        elif _cat==5:
            if stat == Driving.STAT_BACKWARD:
                self.stat = Driving.STAT_BACKWARD
                self._can.wheel(-self.speed)
            else:
                self.stat = Driving.STAT_FORWARD
                self._can.wheel(self.speed)

class Wheel:
    GPIO_SERVO  = 15

    '''
    t       duty cycle          direction
    0.5ms   0.5ms/20ms = 2.5%   0 degs
    1.5ms   1.5ms/20ms = 7.5%   90 degs
    2.5ms   2.5ms/20ms = 12.5%  180 degs
    '''
    MIN_VECTOR  = 2.5
    WITH_VECTOR = 10    # 12.5% - 2.5%

    def __init__(self, bus, addr, freq):
        if _cat==0 or _cat==1 or _cat==3 or _cat==6:
            self.pwm = PWM(bus, addr)
            self.pwm.setFreq(freq)
        elif _cat==5:
            global CAN
            from AutoCar_system import CAN
            self._can=CAN.Car()

        self.centerAngle = 90

    def _angle2duty(self, n):
        return (Wheel.WITH_VECTOR / 180) * n + Wheel.MIN_VECTOR

    def setCenterAngle(self, angle):
        self.centerAngle = angle
    
    def turnLeft(self, angle):
        a = self.centerAngle - angle

        if _cat==1:
            a = self.centerAngle + angle
            
        if _cat==0 or _cat==1 or _cat==3 or _cat==6:
            self.pwm.setDuty(Wheel.GPIO_SERVO, self._angle2duty(a))
            time.sleep(angle / 100)
        elif _cat==5:
            self._can.steer((a-90)/self._can.steer_range)

    def turnRight(self, angle):
        a = self.centerAngle + angle
        
        if _cat==1:
            a = self.centerAngle - angle

        if _cat==0 or _cat==1 or _cat==3 or _cat==6:
            self.pwm.setDuty(Wheel.GPIO_SERVO, self._angle2duty(a))
            time.sleep(angle / 100)
        elif _cat==5:
            self._can.steer((a-90)/self._can.steer_range)
          
    def turnCenter(self):
        if _cat==0 or _cat==1 or _cat==3 or _cat==6:
            self.pwm.setDuty(Wheel.GPIO_SERVO, self._angle2duty(self.centerAngle)) 
        elif _cat==5:
            self._can.steer((self.centerAngle-90)/self._can.steer_range)

class CameraPod:
    Vertical_GPIO  = 14
    Horizontal_GPIO = 13

    def __init__(self, bus=0, addr=0x5d, freq=50):
        if _cat==0 or _cat==1 or _cat==3 or _cat==6:
            self.pwm = PWM(bus, addr)
            self.pwm.setFreq(freq)
            if _cat==3 or _cat==6:
                self.panCenterAngle = 188
            else:
                self.panCenterAngle = 90
            self.tiltCenterAngle = 13
        elif _cat==5:
            global CAN
            from AutoCar_system import CAN
            self._can=CAN.Car()
            self.panCenterAngle = 0
            self.tiltCenterAngle = 0

    def _angle2duty(self, n):
        return n/17.3239 + 1.97

    def panLeft(self, value):
        n=self.panCenterAngle+value

        if _cat==0 or _cat==1 or _cat==3 or _cat==6:
            self.pwm.setDuty(self.Vertical_GPIO,self._angle2duty(n))
        elif _cat==5:
            self._can.camPan(n)

    def panRight(self, value):
        n=self.panCenterAngle-value

        if _cat==0 or _cat==1 or _cat==3 or _cat==6:
            self.pwm.setDuty(self.Vertical_GPIO,self._angle2duty(n))
        elif _cat==5:
            self._can.camPan(n)

    def pan(self, n):
        if _cat==0 or _cat==1 or _cat==3 or _cat==6:
            self.pwm.setDuty(self.Vertical_GPIO,self._angle2duty(self.panCenterAngle-n))
        elif _cat==5:
            self._can.camPan(n+self.panCenterAngle-90)

    def tiltBack(self):
        if _cat==0 or _cat==1 or _cat==3 or _cat==6:
            self.pwm.setDuty(self.Horizontal_GPIO,self._angle2duty(90+(not has_lidar * 90)+self.tiltCenterAngle))
        elif _cat==5:
            self._can.camTilt(90)

    def tiltFront(self):
        if _cat==0 or _cat==1 or _cat==3 or _cat==6:
            self.pwm.setDuty(self.Horizontal_GPIO,self._angle2duty(self.tiltCenterAngle))
        elif _cat==5:
            self._can.camTilt(0)

    def tilt(self, n):
        if _cat==0 or _cat==1 or _cat==3 or _cat==6:
            self.pwm.setDuty(self.Horizontal_GPIO,self._angle2duty(n+self.tiltCenterAngle))
        elif _cat==5:
            self._can.camTilt(n+self.tiltCenterAngle)

class axis6:
    address=0x68

    PW_MGMT_1 = 0x6b
    PW_MGMT_2 = 0x6c

    bus = None

    def __init__(self, bus=1):
        if _cat==0 or _cat==1 or _cat==3:
            self.bus = smbus.SMBus(bus)
            self.bus.write_byte_data(self.address, self.PW_MGMT_1, 0)
        if _cat==6:
            self.bus = smbus.SMBus(8)
            self.bus.write_byte_data(self.address, self.PW_MGMT_1, 0)
        elif _cat==4 or _cat==5 :
            self.bus = smbus.SMBus(8)
            self.bus.write_byte_data(self.address, self.PW_MGMT_1, 0)
        else:
            del self

    def __del__(self):
        self.bus.close()

    def read_word(self, adr):
        while time.time()-__main__.pwm_time_log<0.05: time.sleep(0.01)
        high = self.bus.read_byte_data(self.address, adr)
        low = self.bus.read_byte_data(self.address, adr+1)
        val = (high << 8) + low
        __main__.pwm_time_log=time.time()
        return val

    def read_word_2c(self, adr):
        #for _ in range(10):
            #try:
        val = self.read_word(adr)
        if (val >= 0x8000):
            return -((65535 - val) + 1)
        else:
            return val 
            #except Exception as e:
                #if e.errno == 110:
                #    print("I2C connection timed out. Try again after 0.5sec...\nReset the i2c bus if it continues to occur.")
                #    time.sleep(0.5)
                #pass

    def getGyro(self, axis=None):
        if type(axis)==str:
            if axis.lower()=="x":
                return self.read_word_2c(0x43)
            elif axis.lower()=="y":
                return self.read_word_2c(0x45)
            elif axis.lower()=="z":
                return self.read_word_2c(0x47)
            else:
                x=self.read_word_2c(0x43)
                y=self.read_word_2c(0x45)
                z=self.read_word_2c(0x47)
                return {"x":x, "y":y, "z":z}
        else:
            x=self.read_word_2c(0x43)
            y=self.read_word_2c(0x45)
            z=self.read_word_2c(0x47)
            return {"x":x, "y":y, "z":z}

    def getAccel(self, axis=None):
        if type(axis)==str:
            if axis.lower()=="x":
                return self.read_word_2c(0x3b)
            elif axis.lower()=="y":
                return self.read_word_2c(0x3d)
            elif axis.lower()=="z":
                return self.read_word_2c(0x3f)
            else:
                x=self.read_word_2c(0x3b)
                y=self.read_word_2c(0x3d)
                z=self.read_word_2c(0x3f)
                return {"x":x, "y":y, "z":z}
        else:
            x=self.read_word_2c(0x3b)
            y=self.read_word_2c(0x3d)
            z=self.read_word_2c(0x3f)
            return {"x":x, "y":y, "z":z}

class AutoCar(axis6):
    joystick = None
    steer_limit = 30
    max_speed=99
    min_speed=20

    def __init__(self, bus=0):
        super().__init__()

        if _cat==3 or _cat==6:
            if _cat==6: bus=1
            self.wheel = Wheel(bus, 0x5c, 50)
            self.campod = CameraPod(bus, 0x5c, 50)
        else:
            self.wheel = Wheel(bus, 0x5d, 50)
            self.campod = CameraPod(bus, 0x5d, 50)

        if _cat==1:
            self.drv = Driving(bus, 0x5d, 50)
        elif _cat==0 or _cat==3:
            self.drv = Driving(bus, 0x5e, 200)
        elif _cat==6:
            self.drv = Driving(1, 0x5e, 200)
        else:
            self.drv = Driving(None, None, None)

        if _cat==5:
            from AutoCar_system import CAN
            self._can=CAN.Car()

            def us():
                return self._can.read()

            self.getUltrasonic=us
        

        self._steering = 0.0

    @property
    def steering(self):
        return self._steering

    @steering.setter
    def steering(self, value):
        if value > 1.0 or value < -1.0:
            print("Warning : This value is out of range -1.0 to 1.0. It was adjusted to maximum.")

            if value > 1.0:
                value = 1.0
            elif value < -1.0:
                value = -1.0

        self._steering = value

        if _cat==3 or _cat==6:
            value*=-1

        if _cat==0 or _cat==1 or _cat==3 or _cat==6:
            if value < 0:
                self.wheel.turnLeft(int(abs(value) * self.steer_limit))
            else:
                self.wheel.turnRight(int(value * self.steer_limit))
        elif _cat==5:
            self.wheel._can.steer(value)
    
    @property
    def steering_gain(self):
        return self._steering_gain

    @steering_gain.setter
    def steering_gain(self, value):
        self._steering_gain = value

    def setCenterAngle(self, angle):
        self.wheel.setCenterAngle(angle)

    def correctError(self, value):
        self.setCenterAngle(self.wheel.centerAngle + value * self.steer_limit)

    def turnLeft(self):
        self.steering = -1

    def turnRight(self):
        self.steering = 1

    def turnCenter(self):
        self.steering = 0

    def setSpeed(self, speed):
        self.drv.setSpeed(speed)

    def getSpeed(self):
        return self.drv.getSpeed()

    def stop(self):
        self.drv.stop()
    
    def forward(self, speed=None):
        self.drv.direction(Driving.STAT_FORWARD, speed)
    
    def backward(self, speed=None):
        self.drv.direction(Driving.STAT_BACKWARD, speed)

    def camPan(self, value):
        self.campod.pan(value)

    def camTilt(self, value):
        if has_lidar and value>90: value=90
        self.campod.tilt(value)

    def cam2Back(self):
        self.campod.tiltBack()

    def cam2Front(self):
        self.campod.tiltFront()

    def cam2Left(self, value):
        self.campod.panLeft(value)

    def cam2Right(self, value):
        self.campod.panRight(value)

    def _control_as_joystick(self, value):
        if value['sep'] == "j":
            self.steering=value['x']
            speed=value['y']*(self.max_speed-self.min_speed)

            if speed>0:
                self.forward(speed+self.min_speed)
            elif speed<0:
                self.backward(-speed+self.min_speed)
            else:
                self.stop()


class Driver:

    GPIO_ESC = 12

    GPIO_WHL_1_FORWARD    = 0
    GPIO_WHL_1_BACKWARD   = 1
    GPIO_WHL_2_FORWARD    = 2
    GPIO_WHL_2_BACKWARD   = 3
    GPIO_WHL_3_FORWARD    = 4
    GPIO_WHL_3_BACKWARD   = 5

    MIN_SPEED = 20
    MAX_SPEED = 99

    STEER_LIMIT = 180

    STAT_STOP = 1
    STAT_MOVING = 2
    STAT_SETTING = 3
    STAT_DRIVING = 4

    stat=1

    def __init__(self, bus, addr, freq):
        self.stat = Driver.STAT_STOP
        self.speed = Driver.MIN_SPEED
        self.drct = 0
        self.steer = 0

        try:
            self.pwm = PWM(bus, addr, wait_i2c=False)
            self.pwm.setFreq(freq)
        except:
            pass

    def __del__(self):
        self.stop()

    def whl(self, id, value):
        if id == 1 :
            if value < 0 :
                self.pwm.setDuty(0,abs(value))
                self.pwm.setDuty(1,0)
            elif value > 0 :
                self.pwm.setDuty(0,0)
                self.pwm.setDuty(1,abs(value))
            else :
                self.pwm.setDuty(0,0)
                self.pwm.setDuty(1,0)
        elif id == 2 :
            if value < 0 :
                self.pwm.setDuty(2,abs(value))
                self.pwm.setDuty(3,0)
            elif value > 0 :
                self.pwm.setDuty(2,0)
                self.pwm.setDuty(3,abs(value))
            else :
                self.pwm.setDuty(2,0)
                self.pwm.setDuty(3,0)
        elif id == 3 :
            if value < 0 :
                self.pwm.setDuty(4,abs(value))
                self.pwm.setDuty(5,0)
            elif value > 0 :
                self.pwm.setDuty(4,0)
                self.pwm.setDuty(5,abs(value))
            else :
                self.pwm.setDuty(4,0)
                self.pwm.setDuty(5,0)

    def setSpeed(self, speed):
        if speed:
            if abs(speed) > Driver.MAX_SPEED:
                if speed > 0 :
                    speed = Driver.MAX_SPEED
                elif speed < 0 :
                    speed = -Driver.MAX_SPEED
            elif abs(speed) < Driver.MIN_SPEED:
                if speed > 0 :
                    speed = Driver.MIN_SPEED
                elif speed < 0 :
                    speed = -Driver.MIN_SPEED
            self.speed = speed

        if self.stat == Driver.STAT_MOVING:
            self.move(self.drct, self.speed)
        elif self.stat == Driver.STAT_DRIVING:
            self.drive(self.steer, self.speed)

    def getSpeed(self):
        return self.speed

    def stop(self):
        self.whl(1,0)
        self.whl(2,0)
        self.whl(3,0)

        self.stat = Driver.STAT_STOP

    def setDirection(self, degree):
        self.drct = degree % 360

        if self.stat == Driver.STAT_MOVING:
            self.move(self.drct, self.speed)

    def setSteer(self, degree):
        if abs(degree) > self.STEER_LIMIT :
            if degree > 0 :
                degree = self.STEER_LIMIT
            elif degree < 0 :
                degree = -self.STEER_LIMIT

        self.steer=degree

        if self.stat == Driver.STAT_DRIVING:
            self.drive(self.steer, self.speed)

    def move(self, degree=None, speed=None):
        self.stat = Driver.STAT_SETTING

        if degree is None :
            degree = self.drct
        else :
            self.setDirection(degree)

        if speed is None :
            speed = self.speed
        elif speed == 0 :
            self.stop()
        else :
            self.setSpeed(speed)
        
        w1=math.sin(math.radians(self.drct-300))
        w2=math.sin(math.radians(self.drct-60))
        w3=math.sin(math.radians(self.drct-180))
        
        rate = (1.0/max(abs(w1), abs(w2), abs(w3)))

        w1*=rate*self.speed
        w2*=rate*self.speed
        w3*=rate*self.speed

        self.whl(1,w1)
        self.whl(2,w2)
        self.whl(3,w3)

        self.stat = Driver.STAT_MOVING

    def drive(self, steer=None, speed=None):
        self.stat = Driver.STAT_SETTING

        if steer is None :
            steer = self.steer
        else :
            self.setSteer(steer)

        if speed is None :
            speed = self.speed
        elif speed == 0 :
            self.stop()
            return
        else :
            self.setSpeed(speed)
        
        if abs(steer) != 0 and abs(steer) != 180:
            theta = math.radians(90-steer)

            h = 500 #mm
            rad = {'x':h * math.tan(theta), 'y':0}
            m = 150 #mm

            W_1 = {'x':m * math.cos(math.radians(30)), 'y':m * math.sin(math.radians(30))}
            W_2 = {'x':m * math.cos(math.radians(150)), 'y':m * math.sin(math.radians(150))}
            W_3 = {'x':m * math.cos(math.radians(270)), 'y':m * math.sin(math.radians(270))}

            RW_1 = math.sqrt((W_1['x']-rad['x'])**2 + (W_1['y']-rad['y'])**2) * (steer/abs(steer))
            RW_2 = math.sqrt((W_2['x']-rad['x'])**2 + (W_2['y']-rad['y'])**2) * (steer/abs(steer))
            RW_3 = math.sqrt((W_3['x']-rad['x'])**2 + (W_3['y']-rad['y'])**2) * (steer/abs(steer))

            alpha_1 = math.acos( W_1['y'] / RW_1 ) + math.radians(30)
            alpha_2 = math.acos( W_2['y'] / RW_2 ) + math.radians(150)
            alpha_3 = math.acos( W_3['y'] / RW_3 ) + math.radians(270)

            w1=math.sin(alpha_1)
            w2=math.sin(alpha_2)
            w3=math.sin(alpha_3)

            rate = (1.0/max(abs(w1), abs(w2), abs(w3)))

            w1*=rate*self.speed
            w2*=rate*self.speed
            w3*=rate*self.speed

            self.whl(1,w1)
            self.whl(2,w2)
            self.whl(3,w3)
        elif abs(steer) == 180 :
            self.whl(1,self.speed)
            self.whl(2,-self.speed)
            self.whl(3,0)
        elif abs(steer) == 0 :
            self.whl(1,self.speed)
            self.whl(2,-self.speed)
            self.whl(3,0)

        self.stat = Driver.STAT_DRIVING

    def turnLeft(self):
        self.whl(1,-self.speed)
        self.whl(2,-self.speed)
        self.whl(3,-self.speed)

    def turnRight(self):
        self.whl(1,self.speed)
        self.whl(2,self.speed)
        self.whl(3,self.speed)