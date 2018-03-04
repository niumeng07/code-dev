#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution_Error {
public:
    void lmr_travel(TreeNode* root) {
        if(root == NULL)
            return;
        lmr_travel(root->left);
        lmr.push_back(root->val);
        lmr_travel(root->right);
    }
    void rml_travel(TreeNode* root) {
        if(root == NULL)
            return;
        rml_travel(root->right);
        rml.push_back(root->val);
        rml_travel(root->left);
    }
    void set_zero(TreeNode* root) {
        if (root == NULL) return;
        if (root->left == NULL && root->right != NULL){
        }
        if (root->left != NULL && root->right == NULL){
        }
        set_zero(root->left);
        set_zero(root->right);
    }
    bool isSymmetric(TreeNode* root) {
        set_zero(root);
        lmr_travel(root);
        rml_travel(root);
        if (lmr.size() != rml.size())
            return false;
        for (int i = 0; i < lmr.size(); i++) {
            if (lmr[i] != rml[i])
                return false;
        }
        return true;
    }
    vector<int> lmr;
    vector<int> rml;
};
class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        if(!root) return true;
        return compRoot(root -> left, root -> right);
    }
private:
    bool compRoot(TreeNode* lroot, TreeNode* rroot){
        if(!lroot) return (NULL == rroot);
        if(NULL == rroot) return false;
        if(lroot -> val != rroot -> val) return false;
        return (compRoot(lroot -> left, rroot -> right) && compRoot(lroot -> right, rroot -> left));
    }
};
int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);
    Solution su;
    cout << su.isSymmetric(root) << endl;
}

