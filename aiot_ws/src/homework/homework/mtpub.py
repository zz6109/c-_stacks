import rclpy                    # ros2 노드 초기화, 노드구동, 노드간 통신 활성화
from rclpy.node import Node     # 발행자, 구독자, 서비스, 액션, 타이머 생성
from rclpy.qos import QoSHistoryPolicy, QoSDurabilityPolicy, QoSReliabilityPolicy, QoSProfile
from std_msgs.msg import String, Header
from rclpy.clock import Clock, ClockType

class MTpub(Node):
    def __init__(self):
        super().__init__("mtpub")
        self.qos_profile = QoSProfile(history=QoSHistoryPolicy.KEEP_ALL, 
                                      reliability = QoSReliabilityPolicy.RELIABLE, 
                                      durability = QoSDurabilityPolicy.TRANSIENT_LOCAL) # 양쪽 노드에서 동일하게 설정해주어야함

        self.pub1 = self.create_publisher(String, "message2", self.qos_profile)
        self.pub2 = self.create_publisher(Header, "time", self.qos_profile)

        self.timer1 = self.create_timer(1, self.send_msg)
        self.timer2 = self.create_timer(1, self.send_time)

    def send_msg(self):
        msg = String()
        msg.data = "hello, Master!"
        self.pub1.publish(msg)

    def send_time(self):
        msg = Header()
        msg.frame_id = "time"
        msg.stamp = self.get_clock().now().to_msg()
        print(f"sec: {msg.stamp.sec}, nano sec: {msg.stamp.nanosec}")
        self.pub2.publish(msg)



def main():
    rclpy.init()
    node = MTpub()
    
    try:
        rclpy.spin(node)
    except:
        node.destroy_node() # 키보드로 종료시 에러 비활성화

if __name__ == '__main__' :
    main()