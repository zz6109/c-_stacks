import rclpy                    # ros2 노드 초기화, 노드구동, 노드간 통신 활성화
from rclpy.node import Node     # 발행자, 구독자, 서비스, 액션, 타이머 생성
from user_interface.srv import AddAndOdd


class Service_server(Node):
    def __init__(self):
        super().__init__("Service_server")
        self.create_service(AddAndOdd, "addandodd", self.service_callback)
        self.bool = bool()

    def service_callback(self, request : AddAndOdd.Request, response : AddAndOdd.Response):
        response.stamp = self.get_clock().now().to_msg()
        response.sum = request.inta + request.intb
        if response.sum % 2:
            response.odd = "two ints sum is odd"
        else:
            response.odd = "two ints sum is not odd"
        return response


def main():
    rclpy.init()
    node = Service_server()
    
    try:
        rclpy.spin(node)
    except:
        node.destroy_node() # 키보드로 종료시 에러 비활성화

if __name__ == '__main__' :
    main()