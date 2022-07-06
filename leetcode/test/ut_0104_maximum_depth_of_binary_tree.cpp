#include <string>
#include <vector>
#include "gtest/gtest.h"
#include "0104_maximum_depth_of_binary_tree/maximum_depth_of_binary_tree.h"

TEST(maximum_depth_of_binary_tree0, test0) {
    EXPECT_EQ(Solution().maxDepth(nullptr), 0);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
