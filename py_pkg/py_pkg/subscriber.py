#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from std_msgs.msg import String

class PubNode(Node):

    def __init__(self):
        super().__init__("Music")
        self.counter_ = 0
        self.publisher_ = self.create_publisher(String, "ShivaChants",10)
        self.timer_ = self.create_timer(1,self.publish_chants) 
        self.get_logger().info("Starting Chants....")
    
    def publish_chants(self):
        self.counter_ +=1
        msg = String()
        msg.data = "%s " % self.counter_ + " Om Namah Shivaya!"
        self.publisher_.publish(msg)
        

def main(args=None):
    rclpy.init(args=args)
    node = PubNode()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__=="__main__":
    main()