# CMake 최소 버전 설정
cmake_minimum_required(VERSION 3.18)

# 프로젝트 이름 및 사용할 언어 설정
project(MyProject LANGUAGES C++)

# include 디렉토리를 헤더 파일 검색 경로에 추가
include_directories(${PROJECT_SOURCE_DIR}/include)

# 소스 파일 목록 지정
set(SOURCES
    rational2/main.cpp
    rational2/rational.cpp
)

# 실행 파일 생성
add_executable(MyExecutable ${SOURCES})

