#include <iostream>
#include <limits>
#include <vector>

#include "0008_string2_int/string2_int.h"
#include "gtest/gtest.h"
using namespace std;

TEST(String2Int, test0) {
    String2Int su;
    std::cout << "max int: " << std::numeric_limits<int>::max() << std::endl;
    EXPECT_EQ(su.myAtoi("  +2147483648  "), 2147483647);
    EXPECT_EQ(su.myAtoi("+"), 0);
    EXPECT_EQ(su.myAtoi("+010"), 10);
    std::cout << "min int: " << std::numeric_limits<int>::min() << std::endl;
    EXPECT_EQ(su.myAtoi("  -2147483648  "), -2147483648);
    EXPECT_EQ(su.myAtoi("--15459"), 0);
    EXPECT_EQ(su.myAtoi("--15ldf459"), 0);
    EXPECT_EQ(su.myAtoi(""), 0);
}
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
