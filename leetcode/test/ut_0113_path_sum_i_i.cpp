#include "gtest/gtest.h"
#include <iostream>
#include "0113_path_sum_i_i/path_sum_i_i.h"

int main(int argc, char **argv)
{ 
    PathSumII su;
    /*
     *        0
     *      /   \
     *     1     2
     *    / \    / \
     *   3   7  5   6
     * */
    TreeNode *root = new TreeNode(0);
    TreeNode nodel(1);
    TreeNode noder(2);
    TreeNode nodell(3);
    TreeNode nodelr(7);
    TreeNode noderl(5);
    TreeNode noderr(6);
    root->left = &nodel;
    root->right = &noder;
    nodel.left = &nodell;
    nodel.right = &nodelr;
    noder.left = &noderl;
    noder.right = &noderr;
    vector<vector<int> > res = su.pathSum(root, 8);
    for(auto vec : res)
    {
        for( auto x : vec)
            cout << x << " ";
        cout << endl;
    }
    return 0;
}
