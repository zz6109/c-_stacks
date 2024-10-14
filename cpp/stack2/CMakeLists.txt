#CMakeList.txt
cmake_minimum_required(VERSION 3.18)

#프로젝트 이름
project(testStack)

#실행 파일 추가
add_executable(testStack stack.cpp main.cpp)