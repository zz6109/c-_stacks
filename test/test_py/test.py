import serial

sp = serial.Serial(port='/dev/ttyUSB0', baudrate=9600, timeout=1)

while True:
  if sp.readable():
    rcv = sp.readline()
    print(rcv.decode()[:len(rcv)-1])
