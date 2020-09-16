#include <iostream>

#include "0010_regular_matching/regular_matching.h"
#include "gtest/gtest.h"
using namespace std;

TEST(regular_matching, tets0) {
    EXPECT_TRUE(RegularMatching().isMatch("ab", ".*"));
    EXPECT_TRUE(RegularMatching().isMatch("aa", ".*"));
    EXPECT_TRUE(RegularMatching().isMatch("aa", "aa"));
    EXPECT_TRUE(RegularMatching().isMatch("aa", "a*"));
    EXPECT_TRUE(RegularMatching().isMatch("ab", ".*"));
    EXPECT_TRUE(RegularMatching().isMatch("aab", "c*a*b*"));
}
TEST(regular_matching, tets1) {
    EXPECT_FALSE(RegularMatching().isMatch("ab", ".*c"));
    EXPECT_FALSE(RegularMatching().isMatch("", "..*"));
    EXPECT_FALSE(RegularMatching().isMatch("a", ".*..a*"));
    EXPECT_FALSE(RegularMatching().isMatch("aaa", "ab*a"));
    EXPECT_FALSE(RegularMatching().isMatch("aaa", ".a"));
    EXPECT_FALSE(RegularMatching().isMatch("aa", "a"));
    EXPECT_FALSE(RegularMatching().isMatch("aaa", "aa"));
}
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
