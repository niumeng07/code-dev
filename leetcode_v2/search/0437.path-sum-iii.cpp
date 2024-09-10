/*
给定一个二叉树的根节点 root ，和一个整数 targetSum ，求该二叉树里节点值之和等于 targetSum 的 路径 的数目。
路径 不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。
*/

#include "header.h"

class Solution {
public:
    int result = 0;
    vector<TreeNode*> node_path;
    vector<int> value_path;
    uint64_t current_sum = 0;

    void path_sum_impl(TreeNode* root, int targetSum) {
        node_path.push_back(root);
        value_path.push_back(root->val);
        current_sum += root->val;

        // 并非只有叶子节点才能判断targetSum
        if (current_sum == targetSum && value_path.size() > 0) {
            result++;
        }
        uint64_t tmp_sum = current_sum;
        for (int i = 0; i < value_path.size(); i++) {
            tmp_sum -= value_path[i];
            if (tmp_sum == targetSum && value_path.size() - (i + 1) > 0) {  // 不能把所有元素都删除
                result++;
            }  // 因为有负数，所以没有提前终止条件
        }

        if (root->left != nullptr) {
            path_sum_impl(root->left, targetSum);
        }
        if (root->right != nullptr) {
            path_sum_impl(root->right, targetSum);
        }

        node_path.pop_back();
        value_path.pop_back();
        current_sum -= root->val;
    }

    int pathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) {
            return 0;
        }
        path_sum_impl(root, targetSum);
        return result;
    }
};


int main(int argc, char *argv[]) {
    //
    return 0;
}
