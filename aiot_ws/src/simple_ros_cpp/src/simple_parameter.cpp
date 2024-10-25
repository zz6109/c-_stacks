#include "rclcpp/rclcpp.hpp"
#include "rcl_interfaces/msg/set_parameters_result.hpp"


using namespace std;
using namespace std::chrono_literals;

class Simple_parameter : public rclcpp::Node
{
public:
    Simple_parameter()
        :Node("Simple_parameter")
        {
            declare_parameter<std::string>("my_para", "내가만든 매개 변수");
            _my_para = get_parameter("my_para").as_string();
            _on_set_para_handle = add_on_set_parameters_callback(std::bind(&Simple_parameter::parameter_callback, this, std::placeholders::_1));
             _print_timer = create_wall_timer(1s, std::bind(&Simple_parameter::print_callback, this));
        }
private:
    rclcpp::node_interfaces::OnSetParametersCallbackHandle::SharedPtr _on_set_para_handle;
    rclcpp::TimerBase::SharedPtr _print_timer;
    std::string _my_para;

    void print_callback()
    {
        RCLCPP_INFO(get_logger(), _my_para.c_str());
    }

    rcl_interfaces::msg::SetParametersResult parameter_callback(const std::vector<rclcpp::Parameter> &parameters)
    {
        for (auto parameter : parameters)
        {
            if (parameter.get_name() == "my_para")
            {
                _my_para = parameter.as_string();
            }
        }
        rcl_interfaces::msg::SetParametersResult result;
        result.successful = true;
        return result;
    }
};

int main()
{
    rclcpp::init(0, nullptr);
    auto node = std::make_shared<Simple_parameter>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}





