#include <iostream>
#include <vector>
using namespace std;

class TreeNode {
public:
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : value(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    int depth = 0;
    vector<vector<int> > result;

    void preOrder(TreeNode* root) {
        if (root != NULL) {
            if (result.size() <= depth) {
                vector<int> tmp;
                result.push_back(tmp);
            }
            result[depth].push_back(root->value);
            depth++;
            preOrder(root->left);
            preOrder(root->right);
            depth--;
        }
    }
    vector<vector<int> > levelOrder(TreeNode* root) {
        preOrder(root);
        return result;
    }
    
};
int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left= new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution su;
    vector<vector<int> > result = su.levelOrder(root);
    for (auto vec : result) {
        for (auto x : vec)
            cout << x << ", ";
        cout << endl;
    }
    return 0;
}
