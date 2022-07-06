#include <iostream>
#include <unordered_map>
#include <vector>
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

/* 以节点A为root的最大半径为 left_depth + right_depth
 * 解决思路: 遍历树,给每个节点标上左子树/右子树的最大深度
 * */
class Solution {
public:
    int depth(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        } else {
            return 1 + max(depth(root->left), depth(root->right));
        }
    }

    int diameterOfBinaryTree(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        int diameter = depth(root->left) + depth(root->right);
        diameter = max(diameter, diameterOfBinaryTree(root->left));
        diameter = max(diameter, diameterOfBinaryTree(root->right));
        return diameter;
    }
};
