cmake_minimum_required(VERSION 3.0)

SET(CMAKE_C_COMPILER "/usr/local/bin/gcc-9")
SET(CMAKE_CXX_COMPILER "/usr/local/bin/g++-9")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wunused-value")
project (hello)

include_directories(.)
add_executable(test main.cpp lib.cpp)
