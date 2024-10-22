// cpp은 qos가 기본임
#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/twist.hpp>
#include <turtlesim/msg/color.hpp>
#include <turtlesim/msg/pose.hpp>

class MoveTurtle : public rclcpp::Node {
public:
    MoveTurtle()
        : Node("move_turtle"){
        
        // self.create_timer(0.1, self.twist_pub)
        twist_timer_ = create_wall_timer(
            std::chrono::milliseconds(100),
            std::bind(&MoveTurtle::twist_pub, this));
        // self.create_timer(1/60, self.update)
        update_timer_ = create_wall_timer(
            std::chrono::milliseconds(16), // ~60Hz
            std::bind(&MoveTurtle::update, this));

        // self.pub = self.create_publisher(Twist, "turtle1/cmd_vel", self.qos_profile)
        // this-> 생략가능 동일한 이름의 변수가 없는 한
        pub_ = create_publisher<geometry_msgs::msg::Twist>("turtle1/cmd_vel", 10);

        // self.create_subscription(Pose, "turtle1/pose", self.pose_callback, self.qos_profile)
        pose_sub_ = create_subscription<turtlesim::msg::Pose>(
            "turtle1/pose", 10,
            std::bind(&MoveTurtle::pose_callback, this, std::placeholders::_1));

        // self.create_subscription(Color, "turtle1/color_sensor", self.color_callback, self.qos_profile)
        color_sub_ = create_subscription<turtlesim::msg::Color>(
            "turtle1/color_sensor", 10,
            std::bind(&MoveTurtle::color_callback, this, std::placeholders::_1));


        
    }

private:
    // 메서드들
    void twist_pub() {
        pub_->publish(twist_);
    }

    void pose_callback(const turtlesim::msg::Pose::SharedPtr msg) {
        pose_ = *msg;

        RCLCPP_INFO(this->get_logger(), "Position: x = %f, y = %f, theta = %f", pose_.x, pose_.y, pose_.theta);
    }

    void color_callback(const turtlesim::msg::Color::SharedPtr msg) {
        color_ = *msg;
    }

    void update() {
        // self.twist, self.pose, self.color를 이용한 알고리즘
        // 나선 회전
        twist_.linear.x += 0.001;
        twist_.angular.z = 1.0;
    }

    // 프라이빗에서 변수를 접근할수 있게끔 선언, auto 선언은 접근불가
    // 클래스가 없으면 auto만 써도 됨
    // SharedPtr : 스마트 포인터
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr pub_;
    rclcpp::Subscription<turtlesim::msg::Pose>::SharedPtr pose_sub_;
    rclcpp::Subscription<turtlesim::msg::Color>::SharedPtr color_sub_;
    rclcpp::TimerBase::SharedPtr twist_timer_;
    rclcpp::TimerBase::SharedPtr update_timer_;
    

            
        
        
    // self.twist = Twist()
    geometry_msgs::msg::Twist twist_;

    // self.pose = Pose()
    turtlesim::msg::Pose pose_;

    // self.color = Color()
    turtlesim::msg::Color color_;

};

int main() {
    rclcpp::init(0, nullptr);
    auto node = std::make_shared<MoveTurtle>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
