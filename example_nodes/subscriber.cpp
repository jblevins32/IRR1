#include <memory>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/u_int64.hpp"

class Subscriber : public rclcpp::Node // Define a subscriber that inherits from Node
{
public:
    Subscriber() : Node("Subscriber") // Run the init from Node into the subscriber node
    {
        subscription_ = this->create_subscription<std_msgs::msg::UInt64>(
            "amazing_int", 10, std::bind(&Subscriber::magic_fun, this, std::placeholders::_1));
    }

private:
    void magic_fun(const std_msgs::msg::u_int64::SharedPtr msg) const
    {
        RCLCPP_INFO(this->get_logger(), "Received: %lu", msg->data);
    }

    rclcpp::Subscription<std_msgs::msg::u_int64>::SharedPtr subscription_;
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<Subscriber>());
    rclcpp::shutdown();
    return 0;
}
