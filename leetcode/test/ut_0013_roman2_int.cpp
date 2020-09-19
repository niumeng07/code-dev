#include <iostream>

#include "0013_roman2_int/roman2_int.h"
#include "gtest/gtest.h"
using namespace std;

TEST(roman2_int, test0) {
    EXPECT_EQ(3, Roman2Int().romanToInt("III"));
    EXPECT_EQ(99, Roman2Int().romanToInt("XCIX"));
    EXPECT_EQ(90, Roman2Int().romanToInt("XC"));
    EXPECT_EQ(3333, Roman2Int().romanToInt("MMMCCCXXXIII"));
    EXPECT_EQ(0, Roman2Int().romanToInt("ABC"));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
