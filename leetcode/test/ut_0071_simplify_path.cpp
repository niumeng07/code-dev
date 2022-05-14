#include <string>
#include <vector>
#include "gtest/gtest.h"
#include "0071_simplify_path/simplify_path.h"

TEST(simplify_path0, test0) {
    // EXPECT_EQ(Solution().simplifyPath("/home/"), "/home");
    // EXPECT_EQ(Solution().simplifyPath("/../"), "/");
    // EXPECT_EQ(Solution().simplifyPath("/home//foo"), "/home/foo");
    // EXPECT_EQ(Solution().simplifyPath("/a/./b/../../c///"), "/c");
    EXPECT_EQ(Solution().simplifyPath("////"), "/");
    EXPECT_EQ(Solution().simplifyPath("/"), "/");
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
