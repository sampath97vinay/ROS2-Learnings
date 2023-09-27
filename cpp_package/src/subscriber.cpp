#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"


class SubNode : public rclcpp::Node
{
    public: 

        SubNode(): Node{"Listener"}
        {
        subscriber_ = this->create_subscription<std_msgs::msg::String>("Counter",10,
                     std::bind(&SubNode::listener_callback,this,std::placeholders::_1));
        RCLCPP_INFO(this->get_logger(),"Starting to Listen...");
        }
    private:
        void listener_callback(const std_msgs::msg::String::SharedPtr msg)
        {
            std::string intr_msg = "I heard";
            RCLCPP_INFO(this->get_logger(), strcat(intr_msg.c_str(),msg->data.c_str()));
        }

        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscriber_;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc,argv);
    auto node = std::make_shared<SubNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;

}