#include <rclcpp/rclcpp.hpp>
#include <std_srvs/srv/set_bool.hpp>
#include <chrono>
#include <iostream>

using namespace std;
using namespace std::chrono_literals;

class Service_server : public rclcpp::Node
{
public:
    Service_server()
        : Node("Service_server"){

        server_ = create_service<std_srvs::srv::SetBool>("setbool",
        std::bind(&Service_server::setBool_callback, this, std::placeholders::_1, std::placeholders::_2));

        }
private:
    // 변수형 지정 문이 너무 길어서 typedef 선언
    typedef std::shared_ptr<std_srvs::srv::SetBool::Request> BRequset;
    typedef std::shared_ptr<std_srvs::srv::SetBool::Response> BResponse;
    // self.bool = bool()
    bool _bool;
    void setBool_callback(const BRequset request, BResponse response){
        
        std::string str = request->data ? std::string("true") : std::string("false");
        RCLCPP_INFO(get_logger(), str.c_str());
        if (request->data != _bool)
        {
            _bool = !_bool;
            response->success = true;
            response->message = str + " setting success!!";
        }
        else
        {
            response->success = false;
            response->message = str + " setting fail!!";
        }
    }

    rclcpp::Service<std_srvs::srv::SetBool>::SharedPtr server_;
};

int main() {
    rclcpp::init(0, nullptr);
    auto node = std::make_shared<Service_server>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
