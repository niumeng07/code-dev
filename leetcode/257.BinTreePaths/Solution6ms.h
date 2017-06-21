#include <vector>
#include <iostream>
 
using namespace std;
/**
 * Definition for a binary tree node.
 */
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if( root == NULL)
            return res;
        vector<int> curr;
        Travel( root, curr );
        return this->res;
    }
    void Travel( TreeNode* root, vector<int>& curr)
    {
        curr.push_back(root->val);
        if( root->left == NULL && root->right == NULL)
        {
            string t="";
            t.append(to_string(curr[0]));;
            for(int n = 1; n < curr.size(); n++)
                t.append("->").append(to_string(curr[n]));
            res.push_back(t);
        }
        if( root->left != NULL )
            Travel(root->left, curr);
        if(root->right != NULL )
            Travel(root->right, curr);
        curr.pop_back();
    }

    vector<string> res;
};
