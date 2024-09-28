cmake_minimum_required(VERSION 3.10)
project(s1)

# 设置C++标准
set(CMAKE_CXX_STANDARD 17)

# 添加源文件
set(SOURCES ${CMAKE_SOURCE_DIR}/Cmp/s1/main.cpp ${CMAKE_SOURCE_DIR}/Cmp/s1/s1.cpp)

# 添加可执行文件
add_executable(main ${SOURCES})