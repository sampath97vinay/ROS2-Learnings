from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    ld = LaunchDescription()

    pub_node = Node(
        package = "py_pkg",
        executable = "publisher"
    )     

    sub_node = Node(
        package = "py_pkg",
        executable = "subscriber"
    )

    ld.add_action(pub_node)
    ld.add_action(sub_node)
    return ld