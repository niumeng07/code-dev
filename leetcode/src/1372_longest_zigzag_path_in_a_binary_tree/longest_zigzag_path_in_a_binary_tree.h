#include <iostream>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

/* 思路: dp
 * d(root) = max(1+d(root->left)*方向, 1+d(root->right)*方向)
 * 实现:
 * 1. 需要保存每个节点对应的父节点,(map)
 * 2. 每个节点是其父节点的左/右子节点情况(对应深度的计算)
 * */
class Solution {
public:
    std::unordered_map<TreeNode*, TreeNode*> parents;
    // 如果当前节点是其父的左子节点，对应的max深度
    std::unordered_map<TreeNode *, int> left;
    std::unordered_map<TreeNode *, int> right;
    void dp(TreeNode *node) {
        if (node->left != nullptr) {
            parents.insert(std::make_pair(node->left, node));
        }
        if (node->right != nullptr) {
            parents.insert(std::make_pair(node->right, node));
        }
        TreeNode *p = parents[node];
        left[node] = right[p] + 1;
        right[node] = left[p] + 1;
        dp(node->left);
        dp(node->right);
    }

    int longestZigZag(TreeNode *root) {
        parents.insert(std::make_pair(root, nullptr));
        left.insert(std::make_pair(root, 0));
        right.insert(std::make_pair(root, 0));
        dp(root);
        int maxValue = 0;
        for (const auto &item : left) {
            maxValue = max(maxValue, item.second);
        }
        for (const auto &item : right) {
            maxValue = max(maxValue, item.second);
        }
        return maxValue;
    }
};
