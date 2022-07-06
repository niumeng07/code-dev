#include <string>
#include <vector>
#include "gtest/gtest.h"
#include "0108_convert_sorted_array_to_binary_search_tree/convert_sorted_array_to_binary_search_tree.h"

void MFS(TreeNode* root) {
    if (root == nullptr) {
        return;
    } else {
        MFS(root->left);
        cout << root->val << ", ";
        MFS(root->right);
    }
}

TEST(convert_sorted_array_to_binary_search_tree0, test0) {
    vector<int> nums({1, 2, 3, 4, 5});
    TreeNode* root = Solution().sortedArrayToBST(nums);
    //MFS(root);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
