#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// (递归) O(n)O(n)
/*
 * 当我们用递归去做这个题时不要被题目误导，应该要明确一点
 * 这个函数的功能有三个：给定两个节点 p 和 q
 *
 * 如果 p 和 q 都存在，则返回它们的公共祖先；
 * 如果只存在一个，则返回存在的一个；
 * 如果 p 和 q 都不存在，则返回nullptr
 * 本题说给定的两个节点都存在，那自然还是能用上面的函数来解决
 *
 * 具体思路：
 * （1） 如果当前结点 root 等于 nullptr，则直接返回 nullptr
 * （2） 如果 root 等于 p 或者 q ，那这棵树一定返回 p 或者 q
 * （3） 然后递归左右子树，因为是递归，使用函数后可认为左右子树已经算出结果，用
 * left 和 right 表示 （4） 此时若left 为空，那最终结果只要看 right；若 right
 * 为空，那最终结果只要看 left （5） 如果 left 和 right 都非空，因为只给了 p 和
 * q 两个结点，都非空，说明一边一个，因此 root 是他们的最近公共祖先 （6） 如果
 * left 和 right 都为空，则返回空（其实已经包含在前面的情况中了）
 *
 * 时间复杂度是 O(n)：每个结点最多遍历一次或用主定理，空间复杂度是
 * O(n)：需要系统栈空间
 * */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return nullptr;
        if (root == p || root == q) return root;  // 找到了p或者q
        // 不为 nullptr则为找到p或者q
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        // 不为 nullptr则为找到p或者q
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if (left == nullptr) return right;  // 左侧即未找到p也未找到q, 那p,q一定在右侧
        if (right == nullptr) return left;
        if (left != nullptr && right != nullptr)  // p和q在两侧
            return root;

        return nullptr;  // 必须有返回值
    }
};
