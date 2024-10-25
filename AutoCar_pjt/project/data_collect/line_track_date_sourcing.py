import cv2
import os
from datetime import datetime

# 카메라 열기 (0은 기본 카메라)
cap = cv2.VideoCapture(0)

if not cap.isOpened():
    print("카메라를 열 수 없습니다.")
else:
    # 저장된 사진을 표시할 창 이름
    cv2.namedWindow('Captured Image')  # 캡처된 이미지를 표시할 창

    # 마우스 클릭 이벤트 처리 함수 정의
    def save_image(event, x, y, flags, param):
        if event == cv2.EVENT_LBUTTONDOWN:  # 왼쪽 클릭 시
            dt = datetime.now()
            filename = os.path.join('jpg_data', f'{x}_{y}_{dt.year}-{dt.month}{dt.day}-{dt.hour}:{dt.minute}:{dt.second}.jpg')
            # 폴더가 없으면 생성
            if not os.path.exists('jpg_data'):
                os.makedirs('jpg_data')
            cv2.imwrite(filename, frame)
            print(f"사진이 저장되었습니다: {filename}")

        # 저장된 사진을 새로운 창에 띄우기
            captured_image = cv2.imread(filename)
            if captured_image is not None:
                cv2.imshow('Captured', cv2.circle(captured_image, (x, y), 5, (0, 255, 0), 2))  # 새로운 창에 이미지 표시
            else:
                print("이미지를 불러오는 데 실패했습니다.")

    # 마우스 클릭 이벤트 등록
    cv2.namedWindow('video')  # 창 이름 지정
    cv2.setMouseCallback('video', save_image)

    while True:
        # 프레임 읽기
        ret, frame = cap.read()

        if not ret:
            print("프레임을 읽을 수 없습니다.")
            break

        # 프레임을 윈도우 창에 표시
        cv2.imshow('video', frame)

        # 'q' 키를 누르면 종료
        if cv2.waitKey(1) & 0xFF == ord('q'):
            break

# 카메라 해제 및 모든 창 닫기
cap.release()
cv2.destroyAllWindows()
