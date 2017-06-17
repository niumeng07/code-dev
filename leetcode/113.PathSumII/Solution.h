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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int> > res;   
        if(root == NULL)
            return res;
        vector<int> curr;
        Traversal(res, curr, root, sum);
        return res;
    }
    void Traversal(vector<vector<int> > &res, vector<int> &curr, TreeNode* node, int sum)
    {
        if( node->left == NULL && node->right == NULL)
        {
            if(sumVec(curr) + node->val == sum)
            {
                curr.push_back(node->val);
                res.push_back(curr);
                curr.pop_back();
            }
        }
        if( node->left != NULL)
        {
            curr.push_back(node->val);
            Traversal( res, curr, node->left, sum);
            curr.pop_back();
        }
        if( node->right != NULL)
        {
            curr.push_back(node->val);
            Traversal( res, curr, node->right, sum);
            curr.pop_back();
        }
    }
    int sumVec( vector<int> &nums)
    {
        s = 0;
        for( auto x : nums)
            s += x;
        return s;
    }
    int s;
};
