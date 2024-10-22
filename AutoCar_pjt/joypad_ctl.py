import pygame
import sys

# Pygame 초기화
pygame.init()

# 조이스틱 초기화
pygame.joystick.init()

# 연결된 조이스틱 개수 확인
joystick_count = pygame.joystick.get_count()
if joystick_count == 0:
    print("연결된 조이스틱이 없습니다.")
    sys.exit()

# 첫 번째 조이스틱 연결 (조이스틱이 여러 개일 경우 확장 가능)
joystick = pygame.joystick.Joystick(0)
joystick.init()

# 각종 정보 출력
print(f"조이스틱 이름: {joystick.get_name()}")
print(f"조이스틱 축 개수: {joystick.get_numaxes()}")
print(f"조이스틱 버튼 개수: {joystick.get_numbuttons()}")
print(f"조이스틱 HAT 개수: {joystick.get_numhats()}")

# 이벤트 루프
try:
    while True:
        for event in pygame.event.get():
            # 조이스틱 축 이벤트 처리
            if event.type == pygame.JOYAXISMOTION:
                axis = event.axis
                value = event.value
                print(f"축 {axis} 입력값: {value}")

            # 조이스틱 버튼 이벤트 처리
            elif event.type == pygame.JOYBUTTONDOWN or event.type == pygame.JOYBUTTONUP:
                button = event.button
                state = "눌림" if event.type == pygame.JOYBUTTONDOWN else "뗌"
                print(f"버튼 {button} {state}")

            # HAT(방향 패드) 이벤트 처리
            elif event.type == pygame.JOYHATMOTION:
                hat = event.hat
                value = event.value
                print(f"HAT {hat} 입력값: {value}")

        # CPU 사용량 줄이기 위한 딜레이
        pygame.time.wait(10)

except KeyboardInterrupt:
    print("프로그램을 종료합니다.")
    pygame.quit()
    sys.exit()
