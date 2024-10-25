from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([Node(package="simpleRos", executable="action_client", arguments=[5]), 
                              Node(package="simpleRos", executable="action_server")])