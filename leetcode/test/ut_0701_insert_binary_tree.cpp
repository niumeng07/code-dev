#include <iostream>

#include "0701_insert_binary_tree/insert_binary_tree.h"
#include "gtest/gtest.h"
using namespace std;

void test0() {
    std::cout << "test0" << std::endl;
    TreeNode *root = new TreeNode(100);
    InsertSearchTree().insertIntoBST(root, 30);
    InsertSearchTree().insertIntoBST(root, 0);
    InsertSearchTree().insertIntoBST(root, 130);

    root->printTree(root);
}

int main(int argc, char **argv) {
    test0();
    return 0;
}
