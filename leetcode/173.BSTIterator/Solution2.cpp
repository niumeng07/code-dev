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
public:
    void pushLeft(TreeNode* root) {
        TreeNode* iter = root;
        while (iter != NULL) {
            nodes.push_back(iter);
            iter = iter->left;
        }
    }
    BSTIterator(TreeNode *root) {
        pushLeft(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !nodes.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* current = nodes.back();
        nodes.pop_back();
        if (NULL != current->right) pushLeft(current->right);
        return current->val;
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
