#include <string>
#include <vector>
#include "gtest/gtest.h"
#include "0105_construct_binary_tree_from_preorder_and_inorder_traversal/construct_binary_tree_from_preorder_and_inorder_traversal.h"

TEST(construct_binary_tree_from_preorder_and_inorder_traversal0, test0) {
    vector<int> preorder({3,9,20,15,7});
    vector<int> inorder({9,3,15,20,7});
    EXPECT_EQ(Solution().buildTree(preorder, inorder), nullptr);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
