#include <vector>
#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
void in_travl(vector<int>& result, TreeNode* root){
    if(root!=NULL){
        in_travl(result, root->left);
        result.push_back(root->val);
        in_travl(result, root->right);
    }
}
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        in_travl(result, root);
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
}
