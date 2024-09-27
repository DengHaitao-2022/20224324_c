cmake_minimum_required(VERSION 3.10)
project(S1_Tests)

# 添加Google Test子目录
add_subdirectory(googletest-1.15.2)

# 包含Google Test头文件
include_directories(googletest-1.15.2/googletest/include)

# 添加测试可执行文件
add_executable(test_s1 Cmp/tests/test_s1.cpp Cmp/s1/s1.cpp)

# 链接Google Test库
target_link_libraries(test_s1 gtest gtest_main)