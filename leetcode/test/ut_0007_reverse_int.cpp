#include <iostream>
#include <limits>
#include <vector>

#include "0007_reverse_int/reverse_int.h"
#include "gtest/gtest.h"
using namespace std;

TEST(ut_0007_reverse_int, test0) {
    ReverseInt su;
    EXPECT_EQ(su.reverse(-123), -321);
    EXPECT_EQ(su.reverse(0), 0);
    EXPECT_EQ(su.reverse(1), 1);
    EXPECT_EQ(su.reverse(2), 2);
    EXPECT_EQ(su.reverse(10), 1);
    EXPECT_EQ(su.reverse(-345567), -765543);
    EXPECT_EQ(su.reverse(-3459567), -7659543);
    EXPECT_EQ(su.reverse(1323), 3231);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
