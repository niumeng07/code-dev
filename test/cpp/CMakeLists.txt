cmake_minimum_required(VERSION 3.9)
project(cpp_test)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_BUILD_TYPE Debug)

include_directories("./")

add_executable(uint64_test uint64_test.cpp)

target_link_libraries(uint64_test)
