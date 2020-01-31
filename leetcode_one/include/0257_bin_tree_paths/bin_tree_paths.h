#include <vector>
#include <iostream>
 
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if( root == NULL)
            return res;
        vector<int> curr;
        Travel( root, curr, res);
        return res;
    }
    void Travel( TreeNode* root, vector<int>& curr, vector<string> &res)
    {
        string tmp = _t;
        if(_t.size() > 0)
            _t.append("->").append(to_string(root->val));
        else
            _t.append(to_string(root->val));
        if( root->left == NULL && root->right == NULL)
            res.push_back(_t);
        if( root->left != NULL )
            Travel(root->left, curr, res);
        if(root->right != NULL )
            Travel(root->right, curr, res);
        _t = std::move(tmp);
    }

    string _t;
};
