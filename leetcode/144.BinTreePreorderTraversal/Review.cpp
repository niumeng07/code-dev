#include <iostream>
#include <vector>
#include <string> 
using namespace std;

class Node {
public:
    int value;
    Node* left;
    Node* right;
    Node(int x) : value(x), left(NULL), right(NULL) {}
};

void insert_node(Node* root, int to_insert) {
    if (root == NULL) {
        root = new Node(to_insert);
    }
    else {
        if (to_insert < root->value) {
            if (root->left == NULL) root->left = new Node(to_insert);
            else insert_node(root->left, to_insert);
        } else {
            if (root->right == NULL) root->right = new Node(to_insert);
            else insert_node(root->right, to_insert);
        }
    }
}

Node* build_search_tree(vector<int> &list) {
    if (list.empty())
        return NULL;
    Node* root = new Node(list[0]);
    if (list.size() != 1) {
        for (int i = 1; i < list.size(); i++) {
            insert_node(root, list[i]);
        }
    }
    return root;
}

void preorder_travel(Node* root) {
    if (root == NULL) return;
    cout << root-> value << ", ";
    preorder_travel(root->left);
    preorder_travel(root->right);
}
int main(){
    vector<int> list({1,2,3,4,5,6,7,8,9,10});
    Node* root = build_search_tree(list);
    preorder_travel(root);
}
