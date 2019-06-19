#include <vector>
#include <iostream>
#include <stack>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//中序-递归遍历
void in_travl(vector<int>& result, TreeNode* root){
    if(root!=NULL){
        in_travl(result, root->left);
        result.push_back(root->val);
        in_travl(result, root->right);
    }
}

//中序-循环遍历
void in_travl_w(vector<int>& result, TreeNode* root, stack<TreeNode*> nodes) {
  TreeNode* iter = root;
  while (true) {
    if(iter==NULL && nodes.size() == 0) break;
    if(iter==NULL) {
      iter = nodes.top();
      nodes.pop();
      continue;
    }
    nodes.push(iter);
    iter = iter->left;
    while (iter==NULL && nodes.size()!=0 ) {
      iter = nodes.top();
      nodes.pop();
      result.push_back(iter->val);
      iter = iter->right;
    }
  }
}

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        in_travl(result, root);
        return result;
    }
    vector<int> inorderTraversal_W(TreeNode* root) {
      vector<int> result;
      stack<TreeNode*> nodes;
      in_travl_w(result, root, nodes);
      return result;
    }
};
int main(){
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    Solution su;
    vector<int> result = su.inorderTraversal(root);
    for(auto x : result)
        cout << x << "\t";
    cout << endl;
    result = su.inorderTraversal_W(root);
    for(auto x : result)
        cout << x << "\t";
    cout << endl;
}
