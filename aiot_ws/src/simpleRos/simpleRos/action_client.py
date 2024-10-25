import sys

import rclpy
from action_msgs.msg import GoalStatus
from rclpy.action import ActionClient
from rclpy.action.client import ClientGoalHandle
from rclpy.node import Node
from rclpy.task import Future
from user_interface.action import Fibonacci
from user_interface.action._fibonacci import Fibonacci_GetResult_Response


class Action_client(Node):
    def __init__(self):
        super().__init__("action_client")
        self.action_client: ActionClient = ActionClient(self, Fibonacci, "fibonacci")
        self.future = Future()
        self.get_result_future = Future()

    # 사용자가 지정한 목표(step)를 설정하고 액션 서버에 목표를 전송하는 메서드입니다.
    def send_goal(self, step: str):
        goal_msg : Fibonacci.Goal = Fibonacci.Goal()
        goal_msg.step = int(step)
        while(not self.action_client.wait_for_server(timeout_sec=1)):
            self.get_logger().info("fibonacci server is not available!!")
        self.future : Future= self.action_client.send_goal_async(goal_msg, feedback_callback=self.feedback_callback)
        self.future.add_done_callback(self.goal_response_callback)

    # 서버에서 받은 목표 수락 여부를 처리하는 메서드입니다.
    def goal_response_callback(self, future : Future):
        goal_handle : ClientGoalHandle = future.result() # type: ignore
        if not goal_handle.accepted:
            self.get_logger().info("Goal rejected!!!")
            return
        self.get_logger().info("Goal Accepted!!!")
        self.get_result_future : Future = goal_handle.get_result_async()
        self.get_result_future.add_done_callback(self.get_result_callback)
        self.get_logger().info("end response callback!!!")

    # 서버에서 목표의 최종 결과를 받았을 때 호출되는 콜백 메서드입니다.
    def get_result_callback(self, future : Future):
        result : Fibonacci_GetResult_Response = future.result() # type: ignore
        if result.status == GoalStatus.STATUS_SUCCEEDED:
            self.get_logger().info(f"result: {result.result.seq}")
        if result.status == GoalStatus.STATUS_ABORTED:
            self.get_logger().info("aborted!!")

    # 서버에서 목표 수행 중 피드백을 받았을 때 호출되는 메서드입니다.
    def feedback_callback(self, msg):
        feedback : Fibonacci.Feedback = msg.feedback
        self.get_logger().info( f"Received feedback : {feedback.temp_seq}")

def main(args = None):
    rclpy.init(args=args)
    node = Action_client()
    node.send_goal(sys.argv[1])
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.destroy_node()

if __name__ == "__main__":
    main()
