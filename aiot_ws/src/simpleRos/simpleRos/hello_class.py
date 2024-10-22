import rclpy                    # ros2 노드 초기화, 노드구동, 노드간 통신 활성화
from rclpy.node import Node     # 발행자, 구독자, 서비스, 액션, 타이머 생성
from std_msgs.msg import String

class Hello(Node):
    def __init__(self):
        super().__init__("Hello")
        self.create_timer(1, self.print_hello)
        self.pub = self.create_publisher(String, "send", 10)
        self.number = 0

    def print_hello(self):
        msg = String()
        msg.data = f"hello, Master! + {self.number}"
        self.pub.publish(msg)
        print("hello, Master!")
        self.number += 1

def main():
    rclpy.init()
    node = Hello()
    
    try:
        rclpy.spin(node)
    except:
        node.destroy_node() # 키보드로 종료시 에러 비활성화

if __name__ == '__main__' :
    main()