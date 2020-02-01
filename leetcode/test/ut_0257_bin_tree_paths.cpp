#include "gtest/gtest.h"
#include "0257_bin_tree_paths/bin_tree_paths.h"
#include <vector> 
#include <time.h>
using namespace std;

int main(int argc, char **argv)
{
    BinTreePaths su;

    TreeNode *root = new TreeNode(0);
    root->left = new TreeNode(1);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(61);

    clock_t start, end;
    start = clock();
    vector<string> res = su.binaryTreePaths( root);
    end = clock();
    for( string s : res)
        cout << s << endl;
    cout << "Time used: " << end - start << endl;
    start = clock();
    string x = "abcfd";
    for(int i = 0; i < 100; i++)
    {
        string b = x;
    }
    end = clock();
    cout << "string to string time used: " << end - start << endl;
    return 0;
}

