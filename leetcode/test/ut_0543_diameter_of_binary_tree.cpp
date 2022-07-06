#include <string>
#include <vector>
#include "gtest/gtest.h"
#include "0543_diameter_of_binary_tree/diameter_of_binary_tree.h"

TEST(diameter_of_binary_tree0, test0) {
    EXPECT_EQ(Solution().diameterOfBinaryTree(nullptr), 0);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
