#include <iostream>
#include <stack>
#include <vector>
using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//中序-递归遍历
void in_travl(vector<int> &result, TreeNode *root) {
  if (root != NULL) {
    in_travl(result, root->left);
    result.push_back(root->val);
    in_travl(result, root->right);
  }
}

class Solution {
public:
  vector<int> inorderTraversal(TreeNode *root) {
    vector<int> result;
    in_travl(result, root);
    return result;
  }
  //中序-循环遍历
  vector<int> inorderTraversal_W(TreeNode *root) {
    vector<int> result;
    stack<TreeNode *> nodes;
    TreeNode *iter = root;
    while (iter != NULL || nodes.size() > 0) {
      if (iter == NULL) {
        iter = nodes.top();
        nodes.pop();
        continue;
      }
      nodes.push(iter);
      iter = iter->left;
      while (iter == NULL && nodes.size() != 0) {
        iter = nodes.top();
        nodes.pop();
        result.push_back(iter->val);
        iter = iter->right;
      }
    }

    return result;
  }
};
int main() {
  TreeNode *root = new TreeNode(1);
  root->right = new TreeNode(2);
  root->right->left = new TreeNode(14);
  root->right->left = new TreeNode(3);
  root->left = new TreeNode(10);
  root->left->left = new TreeNode(20);
  root->left->right = new TreeNode(11);
  Solution su;
  vector<int> result = su.inorderTraversal(root);
  for (auto x : result)
    cout << x << "\t";
  cout << endl;
  result = su.inorderTraversal_W(root);
  for (auto x : result)
    cout << x << "\t";
  cout << endl;
}
