#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int value;
    Node* left;
    Node* right;
    Node() : value(0), left(NULL), right(NULL) {}
    Node(int v) : value(v), left(NULL), right(NULL) {}
};
Node* giveTree()
{
    Node* root = new Node(5);
    root->left = new Node(4);
    root->right = new Node(8);
    root->left->left = new Node(11);
    root->left->left->left = new Node(7);
    root->left->left->right = new Node(2);
    root->right->left = new Node(13);
    root->right->right = new Node(4);
    root->right->right->left = new Node(5);
    root->right->right->right = new Node(1);
    return root;
}
void dfs(Node* root, vector<vector<Node*> > &result, vector<Node*> tmp, int &sum, int target)
{
    if(sum == target && root->left == NULL && root->right == NULL)
    {
        result.push_back(tmp);
        tmp.pop_back();
        return;
    }
    if(root->left == NULL && root->right == NULL)
    {
        tmp.pop_back();
        return;
    }
    sum+= root->value;
    dfs(root->left, result, tmp, sum, target);
    sum-= root->value;
    dfs(root->right, result, tmp, sum, target);

}
vector<vector<Node*> > dfs(Node* root, int target)
{
    vector<vector<Node*> > result;
    vector<Node*> tmp;
    int sum_tmp;
    dfs(root, result, tmp, sum_tmp, target);
}
int main()
{
    Node* root = giveTree();
    vector<vector<Node*> > result = dfs(root, 2);
    return 0;
}
