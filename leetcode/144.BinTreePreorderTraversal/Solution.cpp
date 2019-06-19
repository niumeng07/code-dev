#include <iostream>
#include <stdint.h>
#include <vector>
using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#ifndef Node
#define Node TreeNode
#endif

class Solution {
public:
  void btptr(vector<int> &result, TreeNode *root) {
    if (root == NULL)
      return;
    result.push_back(root->val);
    btptr(result, root->left);
    btptr(result, root->right);
  }
  //递归解法
  vector<int> preorderTraversal(TreeNode *root) {
    vector<int> result;
    btptr(result, root);
    return result;
  }
  //非递归解法
  vector<int> preorderTraversalWithQue(TreeNode *root) {
    vector<Node* > tmp;
    vector<int> result;
    Node* iter = root;
    while(true) {
      if(iter!=NULL) {
        tmp.push_back(iter);
        iter = iter->left;
      }
    }
    return result;
  }
};

TreeNode *BuildTree(vector<int> input) {
  vector<TreeNode *> leaf;
  vector<TreeNode *> leaf_new;
  TreeNode *root = NULL;
  for (int i = 0; i < input.size();) {
    if (leaf.empty()) {
      TreeNode *tmp = new TreeNode(input[i]);
      leaf.push_back(tmp);
      i++;
      root = tmp;
    } else {
      for (auto node : leaf) {
        node->left = new TreeNode(input[i]);
        i++;
        node->right = new TreeNode(input[i]);
        i++;
        leaf_new.push_back(node->left);
        leaf_new.push_back(node->right);
      }
      leaf.erase(leaf.begin(), leaf.end());
      vector<TreeNode *> tmp = leaf;
      leaf = leaf_new;
      leaf_new = tmp;
    }
  }
  return root;
}
int main() {
  TreeNode *root = BuildTree({1, 2, 3, 4, 5, 6, 7});
  Solution su;
  vector<int> result = su.preorderTraversal(root);
  for (auto x : result) {
    cout << x << "\t";
  }
  cout << endl;
}
