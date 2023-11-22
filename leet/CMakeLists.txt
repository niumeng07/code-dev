cmake_minimum_required(VERSION 3.0)

SET(CMAKE_C_COMPILER "/opt/homebrew/Cellar/llvm/17.0.3/bin/clang")
SET(CMAKE_CXX_COMPILER "/opt/homebrew/Cellar/llvm/17.0.3/bin/clang++")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wunused-value")
project (leet)

add_subdirectory(src)
