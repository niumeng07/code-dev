#include <string>
#include <vector>
#include "gtest/gtest.h"
#include "1372_longest_zigzag_path_in_a_binary_tree/longest_zigzag_path_in_a_binary_tree.h"

TEST(longest_zigzag_path_in_a_binary_tree0, test0) {
    EXPECT_EQ(Solution().longestZigZag(nullptr), 0);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
