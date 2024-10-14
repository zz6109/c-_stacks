import serial, pymysql

sp = serial.Serial(port='/dev/ttyUSB0', baudrate=9600, timeout=1)

conn = pymysql.connect(host='127.0.0.1', user='root', password='1234', db='dht11', charset='utf8')
curs = conn.cursor()

sql = "select *  from dht11.location1"
curs.execute(sql)

while True:
  if sp.readable():
    rcv = sp.readline()
    if (rcv.decode()[0:4]=="humi"):
      humi = int(rcv.decode()[4:6])
      print(humi)
    if (rcv.decode()[0:4]=="temp"):
      temp = int(rcv.decode()[4:6])
      print(temp)
      sql = "insert into dht11.location1(Temperature, Humidity) VALUES"
   # print(rcv.decode()[:len(rcv)-1])
