cmake_minimum_required(VERSION 3.0)

SET(CMAKE_C_COMPILER "/usr/local/bin/gcc-10")
SET(CMAKE_CXX_COMPILER "/usr/local/bin/g++-10")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wunused-value")
project (hello)

add_subdirectory(src)
add_subdirectory(test)
