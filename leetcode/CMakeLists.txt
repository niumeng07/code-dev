cmake_minimum_required(VERSION 3.0)

SET(CMAKE_C_COMPILER "/usr/local/opt/llvm/bin/clang")
SET(CMAKE_CXX_COMPILER "/usr/local/opt/llvm/bin/clang++")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wunused-value")
project (hello)

add_subdirectory(src)
add_subdirectory(test)
