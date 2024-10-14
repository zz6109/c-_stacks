import pygame

# Pygame 및 조이패드 초기화
pygame.init()
pygame.joystick.init()

# 조이패드가 연결되어 있는지 확인
if pygame.joystick.get_count() > 0:
    joystick = pygame.joystick.Joystick(0)
    joystick.init()
    print(f"조이패드 이름: {joystick.get_name()}")
    print(f"버튼 개수: {joystick.get_numbuttons()}")
    print(f"축 개수: {joystick.get_numaxes()}")
    print(f"HAT 개수: {joystick.get_numhats()}")

# 입력을 처리하는 루프
running = True
while running:
    # for event in pygame.event.get():
    #     if event.type == pygame.QUIT:
    #         running = False

    #     # 버튼이 눌렸을 때
    #     if event.type == pygame.JOYBUTTONDOWN:
    #         print(f"버튼 {event.button}이 눌렸습니다.")
        
    #     # 버튼이 떼졌을 때
    #     if event.type == pygame.JOYBUTTONUP:
    #         print(f"버튼 {event.button}이 떼어졌습니다.")

    # 모든 버튼의 값을 실시간으로 출력
    # for i in range(joystick.get_numbuttons()):
    #     if joystick.get_button(i) != 0.0:
    #         button_value = joystick.get_button(i)
    #         print(f"버튼 {i} 값: {button_value}")

    # 모든 축의 값을 실시간으로 출력
    for i in range(joystick.get_numaxes()):
        # if joystick.get_numaxes() == 5:
        # if joystick.get_axis() != -1.0:
        print(f"축 5값: {joystick.get_axis(i)}")

    # 모든 HAT의 값을 실시간으로 출력
    # for i in range(joystick.get_numhats()):
    #     if joystick.get_hat(i) != 0:
    #         hat_value = joystick.get_hat(i)
    #         print(f"HAT {i} 값: {hat_value}")

    pygame.time.wait(100)  # 0.1초 대기
