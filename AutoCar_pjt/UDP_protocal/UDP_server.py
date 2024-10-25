from pop import Pilot
import socket, threading, project.TCP_protocal.AC_horn as AC_horn
import project.TCP_protocal.parameter_calculate as pc
# import avoid_blocked as ab

# 차량 변수
AC = Pilot.AutoCar()

# 차량 LED 설정 변수
AC_led = Pilot.PWM(1, 0x5c)
AC_led.setFreq(50)

# 장애물 인식 시스템 시작 변수
start_parameter = 0

# 멀티 쓰레딩 변수
# model_threading = threading.Thread(target=ab.avoid_model)

# LED_toggle 변수
status = 0

# 서버 설정
host = "192.168.189.205"  # 서버의 IP 주소 또는 도메인 이름
port = 30000  # 포트 번호

# 서버 소켓 생성 (UDP)
server_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
server_socket.bind((host, port))

print(f"UDP 서버가 {host}:{port}에서 대기 중입니다...")

# 장애물 회피 모델 활성화
# if start_parameter == 0:
#     model_threading.start()
#     start_parameter = 1

while True:
    try:
        # 클라이언트로부터 요청 받기 (UDP는 연결이 없으므로 recvfrom 사용)
        data, client_address = server_socket.recvfrom(1024)  # 클라이언트 주소와 함께 수신
        data = data.decode("utf-8")
        
        if not data:
            continue

        # 요청 파싱
        parts = data.split("&&")
        if len(parts) != 0:
            command = int(parts[0])
            if parts[1] != 0:
                if len(parts[1]) > 1:
                    # 들어오는 값이 한자리 초과면 실수로 처리
                    value = float(parts[1])
                else:
                    # 들어오는 값이 한자리면 정수로 처리
                    value = int(parts[1])

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

                if command == 5 and type(value) == float:
                    speed = pc.cal_speed(value)
                    AC.forward(speed)
                    # RT 버튼입력 전진
                    # if ab.avoid_model() > 0.85:
                    #     # 장애물 감지 시 전진 잠굼
                    #     print(f"장애물 변수 확인 {ab.avoid_model()}")
                    #     AC.stop()
                    #     AC_horn.warning_horn()
                    # else:
                    #     print(f"장애물 변수 확인 {ab.avoid_model()}")
                    #     speed = pc.cal_speed(value)
                    #     AC.forward(speed)

                if command == 0 and type(value) == int:
                    # A 버튼 입력 차량 정지
                    AC.stop()

                if command == 1 and type(value) == int:
                    # B 버튼 입력 경적 울림
                    AC_horn.chime_horn()

                if command == 2 and type(value) == int:
                    if value == 1:
                        # X 버튼 입력 차량 전조등, 후미등(토글)
                        status = not status
                        if status == 0:
                            AC_led.setDuty(4, 0)
                            AC_led.setDuty(5, 0)
                            # red
                            AC_led.setDuty(2, 0)
                            AC_led.setDuty(3, 0)
                        else:
                            # green
                            AC_led.setDuty(4, 99)
                            AC_led.setDuty(5, 99)
                            # red
                            AC_led.setDuty(2, 99)
                            AC_led.setDuty(3, 99)

                if command == 3 and type(value) == int:
                    # Y 버튼 입력 카메라 위치 정렬
                    AC.camPan(95)
                    AC.camTilt(0)

        else:
            pass

    except Exception as e:
        print(f"오류 발생: {e}")

    finally:
        print("연결 종료")
