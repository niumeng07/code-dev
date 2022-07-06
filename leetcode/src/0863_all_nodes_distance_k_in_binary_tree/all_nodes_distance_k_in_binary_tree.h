#include <iostream>
using namespace std;

/*
 * 给定一个二叉树（具有根结点 root）， 一个目标结点 target ，和一个整数值 k 。
 * 返回到目标结点 target 距离为 k 的所有结点的值的列表。 答案可以以 任何顺序 返回。
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
 * 遍历target子节点找出距离为K的节点
 * 清空target节点的子节点
 * 将剩下的二叉树转为以target节点为根节点的二叉树
 * 再次遍历target子节点找出距离为K的节点
 * */
class Solution {
public:
    vector<int> res;
    int distance;
    TreeNode* tar;

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if (!root) return {};
        if (k == 0) return {target->val};
        distance = k;
        tar = target;
        dfs(target, 0);  // 遍历**target**子节点找出距离为K的节点
        target->left = nullptr;
        target->right = nullptr;  //清空**target**节点的子节点
        if (root != target) {
            // 将剩下的二叉树转为以**target**节点为根节点的二叉树
            dfsFindNode(root);
            dfs(target, 0);  // 再次遍历**target**子节点找出距离为K的节点
        }
        return res;
    }

    // 回溯，回溯之前把子节点中包含target节点的子节点设为空，回溯之后把父节点放到这个空子节点中
    bool dfsFindNode(TreeNode* root) {
        if (!root) return false;
        if (root == tar) return true;
        if (dfsFindNode(root->left)) {
            if (!root->left->left) {
                root->left->left = root;
            } else if (!root->left->right) {
                root->left->right = root;
            }
            root->left = nullptr;
            return true;
        }
        if (dfsFindNode(root->right)) {
            if (!root->right->left) {
                root->right->left = root;
            } else if (!root->right->right) {
                root->right->right = root;
            }
            root->right = nullptr;
            return true;
        }
        return false;
    }

    void dfs(TreeNode* root, int step) {
        if (!root) return;
        if (step == distance) {
            res.push_back(root->val);
        }
        dfs(root->left, step + 1);
        dfs(root->right, step + 1);
    }
};
