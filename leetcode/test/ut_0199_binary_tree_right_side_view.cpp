#include <iostream>

#include "0199.binary_tree_right_side_view/binary_tree_right_side_view.h"
#include "gtest/gtest.h"
using namespace std;

// TEST(regular_matching, tets0) {
//   EXPECT_TRUE(RegularMatching().isMatch("aab", "c*a*b*"));
// }
// TEST(regular_matching, tets1) {
//   EXPECT_FALSE(RegularMatching().isMatch("aaa", "aa"));
// }

TEST(binary_tree_right_side_view, test0) {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);

    vector<int> res = Solution().rightSideView(root);

    vector<int> expected({1, 2});
    EXPECT_EQ(res, expected);

    expected = {};
    EXPECT_EQ(Solution().rightSideView(nullptr), expected);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
