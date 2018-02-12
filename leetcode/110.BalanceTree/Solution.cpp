#include <iostream>
#include <unistd.h>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode* BuildTree(vector<int> input){
    vector<TreeNode* > leaf;
    vector<TreeNode* > leaf_new;
    TreeNode* root = NULL;
    for(int i = 0; i < input.size(); ){
        if(leaf.empty()){
            TreeNode* tmp = new TreeNode(input[i]);
            leaf.push_back(tmp);
            i++;
            root = tmp;
        }
        else{
            for(auto node : leaf){
                node->left = new TreeNode(input[i]);
                i++;
                node->right = new TreeNode(input[i]);
                i++;
                leaf_new.push_back(node->left);
                leaf_new.push_back(node->right);
            }
            leaf.erase(leaf.begin(), leaf.end());
            vector<TreeNode* > tmp = leaf;
            leaf = leaf_new;
            leaf_new = tmp;
        }
    }
    return root;
}
class preTravelTree {
public:
    void btptr(vector<int>& result, TreeNode* root){
        if(root == NULL)
            return;
        result.push_back(root->val);
        cout << root->val << ", ";
        btptr(result, root->left);
        btptr(result, root->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        btptr(result, root);
        cout << endl;
        return result;
    }
};

class MaxTreeDepth {
    public:
    MaxTreeDepth() : max(0) {}
    void dfs(vector<int>& result, TreeNode* root){
        if(root == NULL)
            return;
        result.push_back(root->val);
        max = result.size() > max ? result.size() : max;
        dfs(result, root->left);
        dfs(result, root->right);
        result.pop_back();
    }

    int maxDepth(TreeNode* root) {
        vector<int> result;
        dfs(result, root);
        return max;
    }
    int max;
};
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        MaxTreeDepth mleft;
        MaxTreeDepth mright;

        if(abs(mleft.maxDepth(root->left) - mright.maxDepth(root->right) ) <= 1){
            return isBalanced(root->left) && isBalanced(root->right);
        }
        else
            return false;
    }
};
int main(){
    /*`
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2); root->right = new TreeNode(2);
    root->left->left = new TreeNode(3); root->left->right = new TreeNode(3);
    root->left->left->left = new TreeNode(4);
    */
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9); root->right = new TreeNode(20);
    root->right->left = new TreeNode(15); root->right->right = new TreeNode(7);
    Solution su;
    cout << su.isBalanced(root) << endl;
}
