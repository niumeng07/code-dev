#include "gtest/gtest.h"
#include <string>
#include <vector>
#include "0044_wildcard_matching/wildcard_matching.h"

TEST(wildcard_matching0, test0) {
    EXPECT_EQ(Solution().isMatch("aa", "*"), true);
    EXPECT_EQ(Solution().isMatch("aa", "a"), false);
    EXPECT_EQ(Solution().isMatch("cb", "*a"), false);
    EXPECT_EQ(Solution().isMatch("adceb", "*a*b"), true);
    EXPECT_EQ(Solution().isMatch("acdcb", "a*c?b"), false);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
