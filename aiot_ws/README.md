# ros2 humble
## study ros_package
<hr/>


## 241017 수업 내용
### https://docs.ros.org/en/humble/Tutorials/Beginner-CLI-Tools.html
### node, topic, service, action, param 항목 학습

### .bashrc 파일에 소스명령 추가

### simpleRos 패키지 생성 및 hello 명령 작성

<hr/>

## 241018 수업 내용

import rclpy                    # ros2 노드 초기화, 노드구동, 노드간 통신 활성화
from rclpy.node import Node     # 발행자, 구독자, 서비스, 액션 생성

노드 업데이트 하려면 작업공간에서 colcon build 해주어야 함

명령 간소화 명령어 alias
예시: alias cb='colcon build --symlink-install' # 예시 명령어 bashrc에 추가됨
bashrc에 명령줄을 추가해줘야만 매번 alias 명령을 실행할 필요가 없다

셋업에서 콤마 잊지마라!

ros2 run: 한개의 node 실행
install(TARGETS hello_pub hello_pub_lambda hello_pub_class hello_sub DESTINATION lib/${PROJECT_NAME})


ros2 launch: 복수 node 실행
install(TARGETS 
  파일이름
  DESTINATION lib/${PROJECT_NAME})
install(DIRECTORY launch DESTINATION share/${PROJECT_NAME})

### c++ cmake 형식
add_executable(hello_pub src/hello_pub.cpp)

#include "rclcpp/rclcpp.hpp" : rclcpp
#include "std_msgs/msg/string.hpp" :std_msg

ament_target_dependencies(<파일이름> rclcpp std_msg)



BEST_EFFORT