import rclpy                    # ros2 노드 초기화, 노드구동, 노드간 통신 활성화
from time import sleep
from rclpy.node import Node     # 발행자, 구독자, 서비스, 액션, 타이머 생성
from std_srvs.srv import SetBool


class Service_server(Node):
    def __init__(self):
        super().__init__("Service_server")
        self.create_service(SetBool, "setbool", self.setBool_callback)
        self.bool = bool()

    def setBool_callback(self, request : SetBool.Request, response : SetBool.Response):
        self.get_logger().info(f"{request.data}")
        self.get_logger().info(f"{self.bool}")
        if request.data != self.bool:
            self.bool = not self.bool
            response.success = True
            response.message = f"{self.bool} setting sucess"

        else:
            response.success = False
            response.message = f"{self.bool} setting fail"
        sleep(5)
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