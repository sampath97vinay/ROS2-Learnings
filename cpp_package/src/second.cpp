#include "rclcpp/rclcpp.hpp"

class OOPNode : public rclcpp::Node
{

    public:
        OOPNode():Node("Second_node"), counter_(0)
        {
            RCLCPP_INFO(this->get_logger(), "Hello ROS2");

            timer_ = this->create_wall_timer(std::chrono::seconds(2), std::bind(&OOPNode::TimerCallback, this));
        }
    private:
    
        void TimerCallback(){

            counter_++;
            RCLCPP_INFO(this->get_logger(), "Hello %d", counter_);

        }

        rclcpp::TimerBase::SharedPtr timer_;
        int counter_;

};

int main(int argc, char **argv){

    rclcpp::init(argc,argv);
    auto node = std::make_shared<OOPNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}