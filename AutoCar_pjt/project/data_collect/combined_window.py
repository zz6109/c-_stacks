import sys
import cv2
from PyQt5.QtWidgets import QApplication, QLabel, QVBoxLayout, QWidget, QMainWindow
from PyQt5.QtGui import QImage, QPixmap
from PyQt5.QtCore import QTimer

class CombinedWindow(QMainWindow):
    def __init__(self):
        super().__init__()

        self.setWindowTitle("")

        # 메인 위젯 생성
        self.central_widget = QWidget(self)
        self.setCentralWidget(self.central_widget)

        # 레이아웃 설정
        self.layout = QVBoxLayout(self.central_widget)

        # QLabel 두 개 생성
        self.video_label = QLabel(self)
        self.captured_label = QLabel(self)

        # 레이아웃에 QLabel 추가
        self.layout.addWidget(self.video_label)
        self.layout.addWidget(self.captured_label)

        # 타이머 설정
        self.timer = QTimer(self)
        self.timer.timeout.connect(self.update_frames)
        self.timer.start(30)

        # OpenCV 창으로부터 비디오 캡처 객체 받기
        # 각각의 비디오 캡처는 실제로 이미 만들어둔 코드의 창에서 가져오는 부분에 맞춰 연결해야 함
        self.cap_video = cv2.VideoCapture(0)  # video 창
        self.cap_captured = cv2.VideoCapture(1)  # captured 창

    def update_frames(self):
        # video 창에서 프레임 받아오기
        ret_video, frame_video = self.cap_video.read()
        if ret_video:
            self.display_frame(self.video_label, frame_video)

        # captured 창에서 프레임 받아오기
        ret_captured, frame_captured = self.cap_captured.read()
        if ret_captured:
            self.display_frame(self.captured_label, frame_captured)

    def display_frame(self, label, frame):
        # OpenCV 프레임을 RGB로 변환하여 QLabel에 표시
        rgb_frame = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
        h, w, ch = rgb_frame.shape
        bytes_per_line = ch * w
        q_img = QImage(rgb_frame.data, w, h, bytes_per_line, QImage.Format_RGB888)
        label.setPixmap(QPixmap.fromImage(q_img))

    def closeEvent(self, event):
        # 프로그램 종료 시 카메라 해제
        self.cap_video.release()
        self.cap_captured.release()
        event.accept()

if __name__ == "__main__":
    app = QApplication(sys.argv)
    window = CombinedWindow()
    window.show()
    sys.exit(app.exec_())
