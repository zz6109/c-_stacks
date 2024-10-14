from pop import Pilot

# 장애물 인식 모델 멀티쓰레드로 병렬실행
# 1. 장애물 회피후 5초 지연 실행
# 2. 장애물 감지시 경고음 출력, 후진 및 조향허용

# 장애물 인식 모델 불러오기
cam = Pilot.Camera(width=300, height=300)
CA=Pilot.Collision_Avoid(cam)
CA.load_model(path="Project/python/notebook/models/collision_avoid_model.pth")

def avoid_model():
    while True:
        return CA.run()