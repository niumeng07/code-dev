#include <algorithm>
#include <iostream>
#include <vector>

#include "0014_longest_common_prefix/longest_common_prefix.h"
#include "gtest/gtest.h"

TEST(longest_common_prefix, test0) {
    vector<string> input({"flower","flow","flight"});
    EXPECT_EQ(Solution().longestCommonPrefix(input), "fl");
}

TEST(longest_common_prefix, test1) {
    vector<string> input({"dog","rececar","car"});
    EXPECT_EQ(Solution().longestCommonPrefix(input), "");
}

TEST(longest_common_prefix, test2) {
    vector<string> input({});
    EXPECT_EQ(Solution().longestCommonPrefix(input), "");
}

TEST(longest_common_prefix, test3) {
    vector<string> input({"a", "a", "a", "a"});
    EXPECT_EQ(Solution().longestCommonPrefix(input), "a");
}

TEST(longest_common_prefix, test4) {
    vector<string> input({"a"});
    EXPECT_EQ(Solution().longestCommonPrefix(input), "a");
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
