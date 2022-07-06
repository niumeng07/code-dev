#include <iostream>
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

// 检查树是否轴对称
class Solution {
public:
    bool isSymmetric(TreeNode* left, TreeNode* right) {
        if (left == nullptr && right == nullptr) {
            return true;
        } else if (left != nullptr && right != nullptr) {
            if (left->val != right->val) {
                return false;
            } else {
                return isSymmetric(left->left, right->right) &&
                    isSymmetric(left->right, right->left);
            }
        } else {
            return false;
        }
    }
    bool isSymmetric(TreeNode *root) {
         return isSymmetric(root, root);
    }
};
