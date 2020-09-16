/**
 * @file bin_tree_paths.h
 * @brief -Solution.h 3ms Solution
 *
 * Solution6ms.h 6ms Solution
 * * Given a binary tree, return all root-to-leaf paths.
 * * For example, given the following binary tree:
 * *    1
 * *  /   \
 * * 2     3
 * *  \
 * *   5
 * * All root-to-leaf paths are:
 * * ["1->2->5", "1->3"]
 *
 * @author myliuda@sina.com
 * @version 0.0.1
 * @date 2020-02-08
 */
#include <iostream>
#include <vector>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class BinTreePaths {
public:
    bool rootFirstTravel(TreeNode *root, string &tmp, vector<string> &res) {
        if (root == NULL) {
            res.push_back(std::move(tmp));
        } else {
        }
        return true;
    }
    vector<string> binaryTreePathsRv(TreeNode *root) {
        vector<string> res;

        if (root == NULL) return res;
        // 采用中序遍历
        std::string tmp = "";
        rootFirstTravel(root, tmp, res);
        return res;
    }
    vector<string> binaryTreePaths(TreeNode *root) {
        vector<string> res;
        if (root == NULL) return res;
        vector<int> curr;
        Travel(root, curr, res);
        return res;
    }
    void Travel(TreeNode *root, vector<int> &curr, vector<string> &res) {
        string tmp = _t;
        if (_t.size() > 0)
            _t.append("->").append(to_string(root->val));
        else
            _t.append(to_string(root->val));
        if (root->left == NULL && root->right == NULL) res.push_back(_t);
        if (root->left != NULL) Travel(root->left, curr, res);
        if (root->right != NULL) Travel(root->right, curr, res);
        _t = std::move(tmp);
    }

    string _t;
};
