#include <iostream>
using namespace std;

/*
给你一个整数数组 nums ，其中元素已经按 升序 排列，请你将其转换为一棵 高度平衡 二叉搜索树。
高度平衡 二叉树是一棵满足「每个节点的左右两个子树的高度差的绝对值不超过 1 」的二叉树。
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// vector 是中序
class Solution {
public:
    TreeNode* buildTree(vector<int>& nums, int left_start, int left_end,
                        int right_start, int right_end) {
        int middle = (left_end - left_start) / 2;
        TreeNode* root = new TreeNode(nums[middle], nullptr, nullptr);
        root->left = buildTree(nums, left_start, middle - 1, middle + 1,
                               left_end);
        middle = (right_end - right_start) / 2;
        root->right = buildTree(nums, right_start, middle - 1,
                                middle + 1, right_end);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() == 0) return nullptr;
        int middle = nums.size() / 2;
        TreeNode* root = buildTree(nums, 0, middle - 1, middle + 1,
                                   nums.size() - 1);
        return root;
    }
};
