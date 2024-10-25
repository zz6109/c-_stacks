import os
from glob import glob
from setuptools import find_packages, setup

package_name = 'simpleRos'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        ('share/' + package_name + '/launch', glob(os.path.join('launch','*.launch.py'))),
        ('share/' + package_name + '/param', glob(os.path.join('param', '*.yaml')))
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='kimjaehwan',
    maintainer_email='krcw3789@gmail.com',
    description='SimpleRos demo',   # 수정됨
    license='Apache 2.0',           # 수정됨
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            # 앞의 첫 단어를 명령어로 인식함
            "hello = simpleRos.hello:main",
            "hello_class = simpleRos.hello_class:main",
            "hello_sub_qos = simpleRos.hello_sub_qos:main",
            "hello_sub_depth = simpleRos.hello_sub_depth:main",
            "hello_pub_qos = simpleRos.hello_pub_qos:main",
            "hello_pub_depth = simpleRos.hello_pub_depth:main",
            "time_pub = simpleRos.time_pub:main",
            "move_turtle = simpleRos.move_turtle:main",
            "move_turtle_time = simpleRos.move_turtle_time:main",
            "service_server = simpleRos.service_server:main",
            "service_client = simpleRos.service_client:main",
            "user_int_pub = simpleRos.user_int_pub:main",
            "service_server_int = simpleRos.service_server_int:main",
            "action_client = simpleRos.action_client:main",
            "action_server = simpleRos.action_server:main",
            "simple_parameter = simpleRos.simple_parameter:main",
            "simple_parameter2 = simpleRos.simple_parameter2:main"
            
        ],
    },
)
