# 查找 GTest 库
find_package(GTest REQUIRED)
# GTest 的头文件
include_directories(${GTEST_INCLUDE_DIRS} /usr/local/include/ ../../include)
link_directories(../../lib /usr/local/lib)

add_executable(ut_vector ut_vector.cpp)
target_link_libraries(ut_vector ${GTEST_BOTH_LIBRARIES} pthread )
gtest_discover_tests(ut_vector)
