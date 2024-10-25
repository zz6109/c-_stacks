import rclpy                    # ros2 노드 초기화, 노드구동, 노드간 통신 활성화
from rclpy.node import Node     # 발행자, 구독자, 서비스, 액션, 타이머 생성
from std_srvs.srv import SetBool


class Service_client(Node):
    def __init__(self):
        super().__init__("Service_client")
        self.client = self.create_client(SetBool, "setbool")
        while not self.client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info("service not available")
        self.request = SetBool.Request()
        self.create_timer(0.1, self.update)
        self.send_request()

    def send_request(self):
        self.future = self.client.call_async(self.request)
        self.future.add_done_callback(self.done_callback)

    def done_callback(self, future):
        response : SetBool.Response = future.result()
        self.get_logger().info(f"{response.success}")
        self.get_logger().info(response.message)

    def update(self):
        self.get_logger().info("updating!!")

def main():
    rclpy.init()
    node = Service_client()
    
    try:
        rclpy.spin(node)
    except:
        node.destroy_node() # 키보드로 종료시 에러 비활성화

if __name__ == '__main__' :
    main()