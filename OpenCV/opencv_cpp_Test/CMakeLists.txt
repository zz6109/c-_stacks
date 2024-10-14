#CMakeList.txt
cmake_minimum_required(VERSION 3.18)

#프로젝트 이름
project(helloOpenCV)

#패키지 추가
find_package(OpenCV REQUIRED)

#실행 파일 추가
add_executable(main.cpp helloOpenCV.cpp)

#패키지 링크
target_link_libraries(OpenCVExample ${OpenCV_LIBS})