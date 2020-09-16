#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
void printVector(vector<TreeNode*> head) {
    for (auto x : head) cout << x->val << " ";
    cout << endl;
}
void travelTree(TreeNode* root, vector<TreeNode*>& head) {
    if (root == NULL) return;
    if (root->left != NULL) {
        travelTree(root->left, head);
    }
    head.push_back(root);
    if (root->right != NULL) travelTree(root->right, head);
}
class RecoverBinarySearchTree {
public:
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> head;
        travelTree(root, head);
        printVector(head);
        int min = 0;
        int max = head.size() - 1;
        for (int i = 0; i < head.size(); i++) {
            if (i + 1 < head.size() && head[i]->val > head[i + 1]->val) {
                min = i;
                break;
            }
        }
        for (int i = head.size() - 1; i >= 0; i--) {
            if (i - 1 >= 0 && head[i]->val < head[i - 1]->val) {
                max = i;
                break;
            }
        }
        if (head[min]->val > head[max]->val)
            std::swap(head[min]->val, head[max]->val);
        head.resize(0);
        travelTree(root, head);
        printVector(head);
    }
};
