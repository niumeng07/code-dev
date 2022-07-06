#include <string>
#include <vector>
#include "gtest/gtest.h"
#include "0124_binary_tree_maximum_path_sum/binary_tree_maximum_path_sum.h"

TEST(binary_tree_maximum_path_sum0, test0) {
    EXPECT_EQ(Solution().maxPathSum(nullptr), 0);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
