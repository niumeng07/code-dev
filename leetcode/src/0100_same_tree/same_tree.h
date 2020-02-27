/**
 * @brief
 * Given a binary tree, check whether it is a mirror of itself (ie, symmetric
 * around its center).
 *
 * For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
 *
 *     1
 *    / \
 *   2   2
 *  / \ / \
 * 3  4 4  3
 * But the following [1,2,2,null,3,null,3] is not:
 *     1
 *    / \
 *   2   2
 *    \   \
 *    3    3
 * Note:
 * Bonus points if you could solve it both recursively and iteratively.
 * 判断一个是树是否严格对称的
 * 1(错). 对称树的左中右(中序遍历)遍历和右中左遍历结果相同
 *    以上两种遍历结果相同的情况下，一定是对称树吗？
 *
 *    [1,2,3,3,null,2,null]
 *
 *         1
 *     2       3
 *   3       2
 *
 * 3 2 1 2 3
 * 3 2 1 2 3
 *
 */
#include <iostream>
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class SameTree {
public:
  bool isSameTree(TreeNode *p, TreeNode *q) {
    if (p == NULL && q == NULL)
      return true;
    if (p != NULL && q != NULL) {
      if (p->val == q->val)
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
      else
        return false;
    } else
      return false;
  }
};

template <typename T> class Node {
public:
  T val;
  Node<T> *left, *right;
  Node(T x) : val(x), left(NULL), right(NULL) {}
};

template <typename T> class MirrorTree {
public:
  bool isMirrorTree(Node<T> *root) {
    return this->isSameTree(root->left, root->right);
  }
  bool isSameTree(Node<T> *left, Node<T> *right) {
    if (left == NULL) {
      return right == NULL;
    } else if (right == NULL) {
      return left == NULL;
    }
    return left->val == right->val &&
           this->isSameTree(left->left, left->right) &&
           this->isSameTree(right->left, right->right);
  }
};

