#include "header.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<TreeNode*> nodes;
    vector<string> results;

    vector<string> binaryTreePaths(TreeNode* root) {
        nodes.push_back(root);
        if (root->left == nullptr && root->right == nullptr) {
            string result = "";
            for (const auto& node : nodes) {
                result += ("->" + std::to_string(node->val));
            }
            results.push_back(result.substr(2, result.size() - 2));
        } else {
            if (root->left != nullptr) {
                binaryTreePaths(root->left);
            }
            if (root->right != nullptr) {
                binaryTreePaths(root->right);
            }
        }
        nodes.pop_back();
        return results;
    }
};

int main(int argc, char *argv[]) {
    return 0;
}
