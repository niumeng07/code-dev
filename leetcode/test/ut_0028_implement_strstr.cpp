#include <string>
#include <vector>
#include "gtest/gtest.h"
#include "0028_implement_strstr/implement_strstr.h"

TEST(implement_strstr0, test0) {
    std::string haystack = "hello", needle = "ll";
    EXPECT_EQ(Solution().strStr(haystack, needle), 2);
    EXPECT_EQ(Solution().strStr("aaaaa", "bba"), -1);
    EXPECT_EQ(Solution().strStr("", ""), 0);
    EXPECT_EQ(Solution().strStr("abc", "c"), 2);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
