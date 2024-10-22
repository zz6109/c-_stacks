import rclpy                    # ros2 노드 초기화, 노드구동, 노드간 통신 활성화
from rclpy.node import Node     # 발행자, 구독자, 서비스, 액션 생성


def print_hello():
    print("hello, Master!")
    print("This is simlink!")

def main():
    rclpy.init()
    node = Node("hello")
    node.create_timer(1, print_hello)
    rclpy.spin(node)

if __name__ == '__main__' :
    main()