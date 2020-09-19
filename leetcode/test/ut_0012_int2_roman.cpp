#include <iostream>

#include "0012_int2_roman/int2_roman.h"
#include "gtest/gtest.h"
using namespace std;

TEST(int2_roman, test0) {
    EXPECT_EQ("CXXIII", Int2Roman().intToRoman(123));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
