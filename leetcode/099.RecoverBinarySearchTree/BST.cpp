#include <vector>
#include <iostream>
using namespace std;

class Node{
public:
    int value;
    Node* left;
    Node* right;
    Node(int x) : value(x), left(NULL), right(NULL) {}
};
void ldr(Node* root, vector<Node*> &result)
{
    if(root == NULL)
        return;
    ldr(root->left, result);
    result.push_back(root);
    ldr(root->right, result);
}
vector<Node* > ldr(Node* root)
{
    vector<Node*> result;
    ldr(root, result);
    return result;
}
// 遍历放到vector里，对vector sort，但只移动value，不直接移动Node*指针
// 1 2 3 4 5 6  ps: 该题只是交换了一些值，并不是完全打乱，完全打乱的话重排即可
// 3 5 1 4 2 6
// 2 5 1 4 3 6
// 1 5 2 4 3 6
// 1 3 2 4 5 6
// 1 2 3 4 5 6
void recovery_bst(Node* root)
{
    vector<Node* > rr = ldr(root);
}
void print_vec(vector<Node*> vec)
{
    for( auto x : vec)
        std::cout << x->value << "\t";
    cout << endl;
}
int main()
{
    Node* root = new Node(3);
    root->left = new Node(1);
    root->right = new Node(5);
    vector<Node* > result = ldr(root);
    print_vec(result);
    return 0;
}
