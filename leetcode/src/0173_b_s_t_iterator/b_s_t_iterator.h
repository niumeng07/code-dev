//#include "Node/Node.h"
#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int val;
    Node *left;
    Node *right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};
class BSTIterator {
public:
    vector<Node *> nodes;
    int index = 0;

public:
    void inorder_travel(Node *root) {
        if (root == NULL) return;
        inorder_travel(root->left);
        nodes.push_back(root);
        inorder_travel(root->right);
    }
    BSTIterator(Node *root) { inorder_travel(root); }

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
        return nodes[index - 1]->val;
    }
};
void insert_treenode(Node *root, int x) {
    if (root == NULL) root = new Node(x);
    if (x < root->val) {
        if (root->left == NULL)
            root->left = new Node(x);
        else
            insert_treenode(root->left, x);
    } else {
        if (root->right == NULL)
            root->right = new Node(x);
        else
            insert_treenode(root->right, x);
    }
}
Node *build_searchtree(vector<int> &list) {
    if (list.empty()) return NULL;
    Node *root = new Node(list[0]);
    for (int i = 1; i < list.size(); i++) {
        insert_treenode(root, list[i]);
    }
    return root;
}
