import rclpy                    # ros2 노드 초기화, 노드구동, 노드간 통신 활성화
from rclpy.node import Node     # 발행자, 구독자, 서비스, 액션, 타이머 생성
from rclpy.qos import QoSHistoryPolicy, QoSDurabilityPolicy, QoSReliabilityPolicy, QoSProfile
from std_msgs.msg import Header
from rclpy.clock import Clock, ClockType


class Time_pub(Node):
    def __init__(self):
        super().__init__("time_pub")
        self.qos_profile = QoSProfile(history=QoSHistoryPolicy.KEEP_ALL, 
                                      reliability = QoSReliabilityPolicy.RELIABLE, 
                                      durability = QoSDurabilityPolicy.TRANSIENT_LOCAL,
                                      depth = 10) # 양쪽 노드에서 동일하게 설정해주어야함

        self.create_timer(1, self.print_hello)
        self.pub = self.create_publisher(Header, "time", self.qos_profile)
        # self.clock = self.get_clock()
        # ROS_TIME, STEADY_TIME(simulation), SYSTEM_TIME(default)
        self.clock = Clock(clock_type=ClockType.STEADY_TIME)

    def print_hello(self):
        msg = Header()
        msg.frame_id = "time"
        msg.stamp = self.clock.now().to_msg()
        print(f"sec: {msg.stamp.sec}, nano sec: {msg.stamp.nanosec}")
        self.pub.publish(msg)

def main():
    rclpy.init()
    node = Time_pub()
    
    try:
        rclpy.spin(node)
    except:
        node.destroy_node() # 키보드로 종료시 에러 비활성화

if __name__ == '__main__' :
    main()