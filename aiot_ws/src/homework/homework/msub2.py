import rclpy                    # ros2 노드 초기화, 노드구동, 노드간 통신 활성화
from rclpy.node import Node     # 발행자, 구독자, 서비스, 액션, 타이머 생성
from rclpy.qos import QoSHistoryPolicy, QoSDurabilityPolicy, QoSReliabilityPolicy, QoSProfile
from std_msgs.msg import String


class Msub2(Node):
    def __init__(self):
        super().__init__("msub2")
        self.qos_profile = QoSProfile(history=QoSHistoryPolicy.KEEP_ALL, 
                                      reliability = QoSReliabilityPolicy.RELIABLE, 
                                      durability = QoSDurabilityPolicy.TRANSIENT_LOCAL) # 양쪽 노드에서 동일하게 설정해주어야함

        self.create_subscription(String, "message2", self.sub_callback_string, self.qos_profile)

    def sub_callback_string(self, msg: String):
        print(msg.data)

def main():
    rclpy.init()
    node = Msub2()
    
    try:
        rclpy.spin(node)
    except:
        node.destroy_node() # 키보드로 종료시 에러 비활성화

if __name__ == '__main__' :
    main()