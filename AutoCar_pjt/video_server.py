from pop import Util
import cv2
import socket
import pickle
import struct

# 소켓 설정
server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
# host_ip = '192.168.189.205'  # A 기기의 IP 주소
host_ip = '10.42.0.240'
port = 29292
socket_address = (host_ip, port)

# 소켓 바인딩 및 연결 대기
server_socket.bind(socket_address)
server_socket.listen(5)
print("서버가 연결 대기 중...")

# 클라이언트(B 기기) 연결 수락
client_socket, addr = server_socket.accept()
print('클라이언트 연결됨:', addr)

# 카메라 시작
cam = Util.gstrmer(width=320, height=240)
camera = cv2.VideoCapture(cam, cv2.CAP_GSTREAMER)

while camera.isOpened():
    ret, frame = camera.read()
    if not ret:
        break

    # 프레임 직렬화
    data = pickle.dumps(frame)
    message = struct.pack("Q", len(data)) + data

    # 클라이언트(B)로 전송
    client_socket.sendall(message)

    # 'q'를 누르면 종료
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

client_socket.close()
camera.release()
cv2.destroyAllWindows()
