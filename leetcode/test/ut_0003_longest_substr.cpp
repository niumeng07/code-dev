#include <iostream>

#include "0003_longest_substr/longest_substr.h"
#include "gtest/gtest.h"

TEST(longest_substr, test0) {
    std::string str = "abcabcbb";
    // std::string r = "abc";
    EXPECT_EQ(LongestSubstr().lengthOfLongestSubstring(str), 3);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
