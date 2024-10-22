cmake_minimum_required(VERSION 3.18)
project(helloOpenCV)

# C++ 표준 설정
set(CMAKE_CXX_STANDARD 11)
set(OpenCV_DIR "/usr/include/opencv4")  # 혹은 적절한 경로


# OpenCV 라이브러리 찾기
find_package(OpenCV REQUIRED)

# # 헤더 파일 포함 경로 추가
# include_directories(${OpenCV_INCLUDE_DIRS})

# # 실행 파일 생성
# add_executable(helloOpenCV helloOpenCV.cpp)

# # OpenCV 라이브러리 연결
# target_link_libraries(helloOpenCV ${OpenCV_LIBS})

add_executable(main helloOpenCV.cpp)
target_link_libraries(main ${OpenCV_LIBS})
target_link_directories(main PUBLIC ${OpenCV_LIB_DIR})

add_executable(mainclass mainclass.cpp)
target_link_libraries(mainclass ${OpenCV_LIBS})
target_link_directories(mainclass PUBLIC ${OpenCV_LIB_DIR})

add_executable(matOp matOp.cpp)
target_link_libraries(matOp ${OpenCV_LIBS})
target_link_directories(matOp PUBLIC ${OpenCV_LIB_DIR})

add_executable(matOp2 matOp2.cpp)
target_link_libraries(matOp2 ${OpenCV_LIBS})
target_link_directories(matOp2 PUBLIC ${OpenCV_LIB_DIR})

add_executable(vecOP vecOP.cpp)
target_link_libraries(vecOP ${OpenCV_LIBS})
target_link_directories(vecOP PUBLIC ${OpenCV_LIB_DIR})

add_executable(drawLine drawLine.cpp)
target_link_libraries(drawLine ${OpenCV_LIBS})
target_link_directories(drawLine PUBLIC ${OpenCV_LIB_DIR})

add_executable(drawPoly drawPoly.cpp)
target_link_libraries(drawPoly ${OpenCV_LIBS})
target_link_directories(drawPoly PUBLIC ${OpenCV_LIB_DIR})