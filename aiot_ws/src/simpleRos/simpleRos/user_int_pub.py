import rclpy                    # ros2 노드 초기화, 노드구동, 노드간 통신 활성화
from rclpy.node import Node     # 발행자, 구독자, 서비스, 액션, 타이머 생성
from user_interface.msg import UserInt


class User_int_pub(Node):
    def __init__(self):
        super().__init__("User_int_pub")

        self.create_timer(1, self.print_hello)
        self.pub = self.create_publisher(UserInt, "send_user", 10)
        self.number = 0

    def print_hello(self):
        msg = UserInt()
        msg.user_int = 5
        msg.user_int2 = 10
        msg.user_int3 = 15
        self.pub.publish(msg)


def main():
    rclpy.init()
    node = User_int_pub()
    
    try:
        rclpy.spin(node)
    except:
        node.destroy_node() # 키보드로 종료시 에러 비활성화

if __name__ == '__main__' :
    main()