#include <iostream>
#include <vector>

using namespace std;

/**
 * Given a binary tree, imagine yourself standing on the right side of it,
 * return the values of the nodes you can see ordered from top to bottom.
 *
 * Example:
 *
 * Input: [1,2,3,null,5,null,4]
 * Output: [1, 3, 4]
 * Explanation:
 *
 *    1            <---           1            <---
 *  /   \                       /
 * 2     3         <---        2               <---
 *  \     \
 *   5     4       <---
 * 1,3,4                       1,2
 * */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> rightSee(TreeNode *root) {
        vector<int> res;
        if (root == nullptr) {
            return res;
        }
        vector<TreeNode*> nodeQueue;
        nodeQueue.push_back(root);
        res.push_back(root->val);
        int size = nodeQueue.size();
        int start = 0;
        while (true) {
            bool stop = true;
            for (int i = start; i < start + size; i++) {
                TreeNode* temp = nodeQueue[i];
                if (temp->left != nullptr) {
                    nodeQueue.push_back(temp->left);
                    stop = false;
                }
                if (temp->right != nullptr) {
                    nodeQueue.push_back(temp->right);
                    stop = false;
                }
            }
            // 终止条件
            if (stop) {
                break;
            }
            res.push_back(nodeQueue.back()->val);  // 最后的节点一定是最右的节点
            start = start + size;
            size = nodeQueue.size() - start;
        }
        return res;
    }

    vector<int> rightSideView(TreeNode *root) {
        if (root == nullptr) return {};
        vector<int> res({root->val});
        vector<int> right = rightSideView(root->right);
        vector<int> left = rightSideView(root->left);
        for (int i = 0;; i++) {
            if (i < right.size())
                res.emplace_back(right[i]);
            else if (i < left.size())
                res.emplace_back(left[i]);
            else
                break;
        }
        return res;
    }
};
