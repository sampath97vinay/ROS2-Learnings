#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from std_msgs.msg import String

class SubNode(Node):

    def __init__(self):
        super().__init__("Devotee")
        self.subscriber_ = self.create_subscription(String, "ShivaChants",self.chanting_loop,10)
        self.get_logger().info("Now Playing...")

    def chanting_loop(self,msg):
        self.get_logger().info(msg.data)

def main(args=None):
    rclpy.init(args=args)
    node = SubNode()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__=="__main__":
    main()