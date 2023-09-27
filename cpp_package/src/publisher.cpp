#include<string>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

class PubNode : public rclcpp::Node
{
    public:
        PubNode() : Node{"Talker"}, counter_{0}
        {
            
            publisher_ = this->create_publisher<std_msgs::msg::String>("Counter",10);
            timer_ = this->create_wall_timer(std::chrono::seconds(1),
            std::bind(&PubNode::Counting,this));
            RCLCPP_INFO(this->get_logger(),"Starting count...");

        }

    private: 
        void Counting(){
            auto msg = std_msgs::msg::String();
            msg.data = std::to_string(counter_);
            publisher_->publish(msg);
            counter_+=1;
        }
        int counter_;
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
        rclcpp::TimerBase::SharedPtr timer_;

};

int main(int argc, char **argv)
{
    rclcpp::init(argc,argv);
    auto node = std::make_shared<PubNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;

}