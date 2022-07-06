#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 给定两个整数数组 preorder 和 inorder ，其中 preorder 是二叉树的先序遍历，
// inorder 是同一棵树的中序遍历，请构造二叉树并返回其根节点。
/* preorder的第一个位置是root
 * 从inorder中找到root,其两侧分别是左子树和右子树的中序
 * 遍历preorder找属于左子树还是右子树得到左/右子树的先序
 * 循环
 *
 * 是否需要所vector切分: 不需要,维护preorder的两个start,end, inorder的两个start,end
 * */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return nullptr;
    }
};
