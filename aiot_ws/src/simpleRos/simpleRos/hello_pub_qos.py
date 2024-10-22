import rclpy                    # ros2 노드 초기화, 노드구동, 노드간 통신 활성화
from rclpy.node import Node     # 발행자, 구독자, 서비스, 액션, 타이머 생성
from rclpy.qos import QoSProfile
from rclpy.qos import QoSHistoryPolicy, QoSDurabilityPolicy, QoSReliabilityPolicy, QoSProfile
from std_msgs.msg import String


class Hello_pub(Node):
    def __init__(self):
        super().__init__("Hello_pub_qos")
        self.qos_profile = QoSProfile(history=QoSHistoryPolicy.KEEP_ALL, 
                                      reliability = QoSReliabilityPolicy.RELIABLE, 
                                      durability = QoSDurabilityPolicy.TRANSIENT_LOCAL) # 양쪽 노드에서 동일하게 설정해주어야함

        self.create_timer(1, self.print_hello)
        self.pub = self.create_publisher(String, "send_to_qos", self.qos_profile)
        self.number = 0

    def print_hello(self):
        msg = String()
        msg.data = f"hello, Master! + {self.number}"
        self.pub.publish(msg)
        print("hello, Master!")
        self.number += 1

def main():
    rclpy.init()
    node = Hello_pub()
    
    try:
        rclpy.spin(node)
    except:
        node.destroy_node() # 키보드로 종료시 에러 비활성화

if __name__ == '__main__' :
    main()