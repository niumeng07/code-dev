#include <iostream>
#include <vector>
using namespace std;
class Node
{
public:
    Node(int x) : value(x), left(NULL), right(NULL) {}
    int value;
    Node* left;
    Node* right;
};
void dfs(Node* curr, vector<string>& result, string& tmp)
{
    tmp += to_string(curr->value) + "->";
    if(curr->left == NULL && curr->right == NULL)
    {
        result.push_back(tmp.substr(0, tmp.size() - 2));
        return;
    }
    string tmp2 = tmp;
    if(!(curr->left == NULL))
        dfs(curr->left, result, tmp);
    tmp = tmp2;
    if(!(curr->right == NULL))
        dfs(curr->right, result, tmp);
    tmp = tmp2;
}
vector<string> RunPath(Node* root)
{
    vector<string> result;
    if(NULL == root)
        return result;
    string tmp = "";
    dfs(root, result, tmp);
    return result;
}
int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(5);
    vector<string> result = RunPath(root);
    for(auto x : result)
        cout << x << endl;
    return 0;
}
