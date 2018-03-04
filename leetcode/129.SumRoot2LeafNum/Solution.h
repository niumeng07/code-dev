#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    int sum_path;
public:
    Solution() : sum_path(0) {}
    bool is_leaf(TreeNode* root) {
        return (root != NULL) && (root->left == NULL) && (root->right == NULL);
    }
    void preorder_travel(TreeNode* root, int &current) {
        if (root == NULL) {
            return;
        } else if (is_leaf(root)) {
            sum_path += current * 10 + root->val;
            return;
        } else {
            current = current * 10 + root->val;
            preorder_travel(root->left, current);
            preorder_travel(root->right, current);
            current = (current - root->val)/10;
            return;
        }
    }
    int sumNumbers(TreeNode* root) {
        sum_path = 0;
        int current = 0;
        preorder_travel(root, current);
        return sum_path;
    }
};


void insert_treenode(TreeNode* root, int x) {
	if (root == NULL)
		root = new TreeNode(x);
	if (x < root->val) {
        if (root->left == NULL) 
            root->left = new TreeNode(x);
        else 
            insert_treenode(root->left, x);
    }
	else {
		if (root->right == NULL) 
            root->right = new TreeNode(x);
        else 
            insert_treenode(root->right, x);
    }
}
TreeNode* build_searchtree(vector<int> list) {
	if (list.empty()) 
        return NULL;
    TreeNode* root = new TreeNode(list[0]);
    for (int i = 1; i < list.size(); i++) {
    	insert_treenode(root, list[i]);
    }
    return root;
}
