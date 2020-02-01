cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
project (hello)

add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(include/Node1)
add_subdirectory(include/Vector1)
add_subdirectory(include/List1)
