cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

# 头文件路径
include_directories(/usr/local/include/ ../include)

# lib的路径
link_directories(../lib /usr/local/lib)

file(GLOB HELLOWORLD_SOURCES "*/*.cpp")
# add_executable(main main.cpp ${HELLOWORLD_SOURCES})
