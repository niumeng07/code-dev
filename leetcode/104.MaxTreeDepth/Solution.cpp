#include <iostream>
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

class Solution {
public:
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

    int max = 0;
};
int main(){
    TreeNode* root = BuildTree({1,2,3,4,5,6,7});
    Solution su;
    cout << su.maxDepth(root) << endl;
}
