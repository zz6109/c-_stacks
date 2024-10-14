#CMakeList.txt
cmake_minimum_required(VERSION 3.18)

#프로젝트 이름
project(testShape)

#실행 파일 추가
add_executable(testShape circle.cpp rectangle.cpp shape.cpp main.cpp)