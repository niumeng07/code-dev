#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class TreeNode {
public:
  TreeNode *left, *right;
  int val;
  TreeNode(int v) : left(NULL), right(NULL), val(v) {}
  TreeNode(TreeNode *l, TreeNode *r, int v) : left(l), right(r), val(v) {}
  void printTree(TreeNode *root) {
    if (root != NULL) {
      std::cout << root->val << " ";
      printTree(root->left);
      printTree(root->right);
    } else {
      std::cout << std::endl;
      return;
    }
  }
};

class InsertSearchTree {
public:
  void process(TreeNode *root, int val) {
    if (root->left == NULL && root->right == NULL) {
      if (val <= root->val)
        root->left = new TreeNode(val);
      else
        root->right = new TreeNode(val);
    } else if (root->left == NULL) {
      if (val <= root->val)
        root->left = new TreeNode(val);
      else
        insertIntoBST(root->right, val);
    } else if (root->right == NULL) {
      if (val <= root->val)
        insertIntoBST(root->left, val);
      else
        root->right = new TreeNode(val);
    } else { // both root->left and root->right not NULL
      if (val <= root->val)
        insertIntoBST(root->left, val);
      else
        insertIntoBST(root->right, val);
    }
  }
  TreeNode *insertIntoBST(TreeNode *root, int val) {
    this->process(root, val);
    return root;
  }
};
