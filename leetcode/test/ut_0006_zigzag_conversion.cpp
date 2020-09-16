#include <iostream>

#include "0006_zigzag_conversion/zigzag_conversion.h"
#include "gtest/gtest.h"
using namespace std;

TEST(ut_0006_zigzag_conversion, test0) {
    EXPECT_EQ(ZigzagConversion().convert("PAYPALISHIRING", 3),
              "PAHNAPLSIIGYIR");
    EXPECT_EQ(ZigzagConversion().convert("", 3), "");
}

TEST(ut_0006_zigzag_conversion, test1) {
    EXPECT_EQ(ZigzagConversion().convert("A", 2), "A");
    EXPECT_EQ(ZigzagConversion().convert("ABC", 2), "ACB");
    EXPECT_EQ(ZigzagConversion().convert("AB", 2), "AB");
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
