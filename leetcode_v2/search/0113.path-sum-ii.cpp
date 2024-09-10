/*
给你二叉树的根节点 root 和一个整数目标和 targetSum ，找出所有 从根节点到叶子节点 路径总和等于给定目标和的路径。
叶子节点 是指没有子节点的节点。
*/

#include "header.h"

class Solution {
public:
    vector<TreeNode*> nodes_path;
    int node_sum = 0;
    vector<int> nodeval;
    vector<vector<int>> results;

    void path_sum_impl(TreeNode* root, int targetSum) {
        nodes_path.push_back(root);
        nodeval.push_back(root->val);
        node_sum += root->val;

        if (root->left == nullptr && root->right == nullptr) {
            if (node_sum == targetSum) {
                results.push_back(nodeval);
            }
        } else {
            if (root->left != nullptr) {
                path_sum_impl(root->left, targetSum);
            }
            if (root->right != nullptr) {
                path_sum_impl(root->right, targetSum);
            }
        }

        nodes_path.pop_back();
        nodeval.pop_back();
        node_sum -= root->val;
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) {
            return results;
        }

        path_sum_impl(root, targetSum);

        return results;
    }
};
