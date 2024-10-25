from AutoCar import AutoCar_system as Pilot
import socket, project.TCP_protocal.AC_horn as AC_horn
import project.TCP_protocal.parameter_calculate as pc

# 차량 변수
AC = Pilot.AutoCar()
# lidar = LiDAR.Rplidar()
AC_led = Pilot.PWM(1,0x5c)
AC_led.setFreq(50)

# toggle 변수
LED_stat = 0    # LED 토글
lidar_stat = 0  # 라이다 토글
lining_stat = 0 # 차선제어 토글

# 시스템 셋업
# lidar.connect()
# 차선 제어 함수 셋업(추가 예정)

# 서버 설정
host = "192.168.250.205"  # 서버의 IP 주소 또는 도메인 이름
port = 20000       # 포트 번호

# 서버 소켓 생성
server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server_socket.bind((host, port))
server_socket.listen(5)

print(f"서버가 {host}:{port}에서 대기 중입니다...")

while True:
    # 클라이언트 연결 대기
    client_socket, client_address = server_socket.accept()
    print(f"클라이언트 {client_address}가 연결되었습니다.")

    while True:

        try:
            # 클라이언트로부터 요청 받기
            data = client_socket.recv(1024).decode("utf-8")
            if not data:
                continue


            # print(f"클라이언트 {data}.")
            print(f"현재 차량의 속도:{AC.getSpeed()}")
            # 요청 파싱
            parts = data.split("&&")
            if len(parts) != 0:
                command = int(parts[0])
                if parts[1] != 0:
                    if len(parts[1]) > 1:
                        # 들어오는 값이 한자리 초과면 0.00...일테니까 실수
                        value = float(parts[1])
                    else:
                        # 들어오는 값이 한자리면 1 또는 0일테니까 정수
                        value = int(parts[1])

                    # HAT 버튼 필요시 사용
                    # if isinstance(command, tuple) and len(command) == 2:

                    if command == 0 and type(value) == float:
                        # 0번 축 버튼입력 카메라 좌우 각도(0~180)
                        angle = pc.cal_pan(value)
                        AC.camPan(angle)

                    if command == 1 and type(value) == float:
                        # 1번 축 버튼입력 카메라 상하 각도(-30~90)
                        angle = pc.cal_tilt(value)
                        AC.camTilt(angle)


                    if command == 2 and type(value) == float:
                        # LT 버튼입력 후진
                        
                        speed = pc.cal_speed(value)
                        AC.backward(speed)

                    if command == 3 and type(value) == float:
                        # 3번 축 버튼입력 조향각도
                        AC.steering = pc.cal_steer(value)

                    if  command == 5 and type(value) == float:
                        # RT 버튼입력 전진
                        # if lidar_stat == 1 and 
                        speed = pc.cal_speed(value)
                        AC.forward(speed)
                        

                    if command == 0 and type(value) == int:
                        # A 버튼 입력 차량 정지
                        AC.stop()

                    if command == 1 and type(value) == int:
                        # B 버튼 입력 경적울림
                        AC_horn.chime_horn()

                    if command == 2 and type(value) == int:
                        if value == 1:
                        # X 버튼 입력 차량 전조등, 후미등(토글)
                            status = not status
                            if status == 0:
                                AC_led.setDuty(4,0)
                                AC_led.setDuty(5,0)
                            # red
                                AC_led.setDuty(2,0)
                                AC_led.setDuty(3,0)
                            else:
                                # green
                                AC_led.setDuty(4,99)
                                AC_led.setDuty(5,99)
                                # red
                                AC_led.setDuty(2,99)
                                AC_led.setDuty(3,99)

                    if command == 3 and type(value) == int:
                        # Y 버튼 입력 카메라 위치 정렬
                        AC.camPan(95)
                        AC.camTilt(-15)
                    
            else:
                print("오류 발생: 클라이언트에서 value 입력 없음")

        except Exception as e:
            print(f"오류 발생: {e}")

        finally:
            # 클라이언트 소켓 닫기
            # print("연결종료")
            pass

    client_socket.close()