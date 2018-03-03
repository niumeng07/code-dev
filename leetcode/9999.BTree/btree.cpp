#include <iostream>
#include <vector>
using namespace std;

class Node{
public:
    Node* left;
    Node* right;
    int value;
    Node(int x) : left(NULL), right(NULL), value(x) {}
};
void insert_treenode(Node* root, int x) {
	if (root == NULL)
		root = new Node(x);
	if (x < root->value) {
        if (root->left == NULL) 
            root->left = new Node(x);
        else 
            insert_treenode(root->left, x);
    }
	else {
		if (root->right == NULL) 
            root->right = new Node(x);
        else 
            insert_treenode(root->right, x);
    }
}
Node* build_searchtree(vector<int> &list) {
	if (list.empty()) 
        return NULL;
    Node* root = new Node(list[0]);
    for (int i = 1; i < list.size(); i++) {
    	insert_treenode(root, list[i]);
    }
    return root;
}

void rotate_left(Node* root) {
    Node* root_tmp = root;
    root = root->right;
    root_tmp->right = root->left;
    root->left = root_tmp;
}
void rotate_right(Node* root) {
    Node* root_tmp = root;
    root = root->left;
    root_tmp->left = root->right;
    root->right = root_tmp;
}
int tree_depth(Node* root) {
    if (root == NULL) 
        return 0;
    else {
        return 1 + max(tree_depth(root->left), tree_depth(root->right));
    }
}
void build_avltree(Node* root) {
    if (root == NULL)
        return;
    if (abs(tree_depth(root->left) - tree_depth(root->right)) <= 1) {
        build_avltree(root->left);
        build_avltree(root->right);
    } else {
        if (tree_depth(root->left) > tree_depth(root->right) + 1) {
            rotate_right(root);
        } else if (tree_depth(root->left) + 1 < tree_depth(root->right)) {
            rotate_left(root);
        }
        build_avltree(root->left);
        build_avltree(root->right);
    }
}

void in_travel(Node* root){
    if (root == NULL)
        return;
    in_travel(root->left);
    cout << root->value << "\t";
    in_travel(root->right);
}
int main() {
    vector<int> list({1, 82, 487, 83, 92, 2, 6, 9, 100, 108});
    Node* root = build_searchtree(list);//是一个搜索树
    in_travel(root);
    build_avltree(root);//旋转为平衡树未完成
    in_travel(root);
}
