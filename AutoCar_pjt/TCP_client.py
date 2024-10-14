import socket, pygame

# 서버 설정
server_address = "192.168.189.205"  # 서버의 실제 IP 주소 또는 도메인 이름
server_port = 20000      # 서버 포트 번호

# 서버에 연결
client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client_socket.connect((server_address, server_port))

# Pygame 초기화
pygame.init()

# 조이패드 초기화
pygame.joystick.init()

# 조이패드가 연결되어 있는지 확인
if pygame.joystick.get_count() == 0:
    print("조이패드를 찾을 수 없습니다.")
    exit()

# 첫 번째 조이패드 가져오기
joystick = pygame.joystick.Joystick(0)
joystick.init()

client_socket.setblocking(False)

while True:
    for event in pygame.event.get():
         # 조이스틱 축 이벤트 처리
        if event.type == pygame.JOYAXISMOTION:
            axis = event.axis
            value = event.value
            print(f"축 {axis} 입력값: {value}")
            client_socket.send(f"{axis}&&{value}".encode("utf-8"))

            # 조이스틱 버튼 이벤트 처리
        elif event.type == pygame.JOYBUTTONDOWN or event.type == pygame.JOYBUTTONUP:
            button = event.button
            state = "0" if event.type == pygame.JOYBUTTONDOWN else "1"
            print(f"버튼 {button} {state}")
            client_socket.send(f"{button}&&{state}".encode("utf-8"))

            # HAT(방향 패드) 이벤트 처리
        elif event.type == pygame.JOYHATMOTION:
            hat = event.hat
            value = event.value
            print(f"HAT {hat} 입력값: {value}")
            client_socket.send(f"{hat}&&{value}".encode("utf-8"))

    # CPU 사용량 줄이기 위한 딜레이
    pygame.time.wait(10)