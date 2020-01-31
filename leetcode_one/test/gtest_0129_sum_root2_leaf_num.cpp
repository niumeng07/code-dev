#include "gtest/gtest.h"
#include "0129_sum_root2_leaf_num/sum_root2_leaf_num.h"
#include <time.h>
#include <iostream>
#include <vector>
using namespace std;


int main(){
    Solution su;
    TreeNode* root = build_searchtree({1,2,3,4,5});
    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);
    clock_t start = clock();
    for (int i = 0; i < 1000; i++) {
        su.sumNumbers(root);
        su.sumNumbers(root2);
    }
    clock_t end = clock();
    cout << "time used: " << end - start << endl;
}
