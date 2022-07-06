#include <string>
#include <vector>
#include "gtest/gtest.h"
#include "0236_lowest_common_ancestor_of_a_binary_tree/lowest_common_ancestor_of_a_binary_tree.h"

TEST(lowest_common_ancestor_of_a_binary_tree0, test0) {
    EXPECT_EQ(Solution().lowestCommonAncestor(nullptr, nullptr, nullptr), nullptr);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
