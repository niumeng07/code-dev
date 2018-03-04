#include <vector>
#include <time.h>
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
    bool commpareRoot(TreeNode* left, TreeNode* right) {
        if (left == NULL && right == NULL) return true;
        if ((left == NULL || right == NULL)) return false;
        if (left->val != right->val) return false;
        return commpareRoot(left->left, right->right) && commpareRoot(left->right, right->left);
    }
    bool isSymmetric(TreeNode* root) {
        return commpareRoot(root, root);
    }
};

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);
    Solution su;

    clock_t start = clock();
    for(int i = 0; i < 10000000; i++)
        su.isSymmetric(root);
    clock_t end = clock();
    cout << "time used: " << end - start << endl;
}

