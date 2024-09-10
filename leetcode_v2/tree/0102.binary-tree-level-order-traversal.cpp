#include "header.h"

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> results;
        if (root == nullptr) {
            return results;
        }
        vector<TreeNode*> curr_level = {root};
        while (curr_level.size() > 0) {
            vector<int> levelValue;
            vector<TreeNode*> next_level;

            for (const auto& curr_node : curr_level) {
                levelValue.push_back(curr_node->val);
                if (curr_node->left != nullptr) {
                    next_level.push_back(curr_node->left);
                }
                if (curr_node->right != nullptr) {
                    next_level.push_back(curr_node->right);
                }
            }
            results.push_back(levelValue);
            curr_level = next_level;
        }

        return results;
    }
};

int main(int argc, char* argv[]) {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(6);

    vector<vector<int>> levelValues = Solution().levelOrder(root);
    for (const auto& vec : levelValues) {
        print_vector(vec);
    }

    levelValues = Solution().levelOrder(nullptr);

    return 0;
}
