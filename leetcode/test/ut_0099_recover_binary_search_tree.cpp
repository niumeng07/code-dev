#include <iostream>

#include "0099_recover_binary_search_tree/recover_binary_search_tree.h"
#include "gtest/gtest.h"
int main(int argc, char** argv) {
    RecoverBinarySearchTree su;
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(2);
    su.recoverTree(root);
    return 0;
}
