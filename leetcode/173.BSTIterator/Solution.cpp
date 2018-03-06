#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class BSTIterator {
public:
    vector<TreeNode*> nodes;
    int index = 0;
public:
    void inorder_travel(TreeNode* root) {
        if (root == NULL)
            return;
        inorder_travel(root->left);
        nodes.push_back(root);
        inorder_travel(root->right);
    }
    BSTIterator(TreeNode *root) {
        inorder_travel(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        if (nodes.empty()) return false;
        if (index < nodes.size()) {
            return true;
        } else {
            return false;
        }
    }

    /** @return the next smallest number */
    int next() {
        index++;
        return nodes[index-1]->val;
    }
};
void insert_treenode(TreeNode* root, int x) {
	if (root == NULL)
		root = new TreeNode(x);
	if (x < root->val) {
        if (root->left == NULL) 
            root->left = new TreeNode(x);
        else 
            insert_treenode(root->left, x);
    }
	else {
		if (root->right == NULL) 
            root->right = new TreeNode(x);
        else 
            insert_treenode(root->right, x);
    }
}
TreeNode* build_searchtree(vector<int> &list) {
	if (list.empty()) 
        return NULL;
    TreeNode* root = new TreeNode(list[0]);
    for (int i = 1; i < list.size(); i++) {
    	insert_treenode(root, list[i]);
    }
    return root;
}
int main() {
    vector<int> list({1, 82, 487, 83, 92, 2, 6, 9, 100, 108});
    TreeNode* root = build_searchtree(list);//是一个搜索树
    BSTIterator i = BSTIterator(root);
    cout << "build class." << endl;
    while (i.hasNext()) 
        cout << i.next() << ", ";
    return 0;
}
