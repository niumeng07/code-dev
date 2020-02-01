/**
 * @brief
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The digits are stored in reverse order and each of their nodes
 * contain a single digit. Add the two numbers and return it as a linked list.
 *
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 *
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 *
 */
#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}

  void print() {
    ListNode *tmp = this->next;
    std::cout << this->val << "->" << std::ends;
    if (tmp != NULL)
      tmp->print();
    else
      std::cout << std::endl;
  }
};

class AddTwoNumber {
public:
  int andOne = 0;
  ListNode *addTwoNumbers(ListNode *left, ListNode *right) {
    if (left == NULL && right == NULL) {
      if (this->andOne == 1) {
        ListNode *result = new ListNode(this->andOne);
        return result;
      } else
        return NULL;
    }

    if (left == NULL) {
      ListNode *result = new ListNode((0 + right->val + this->andOne) % 10);
      this->andOne = (0 + right->val + this->andOne) / 10;
      result->next = addTwoNumbers(NULL, right->next);
      return result;
    }
    if (right == NULL) {
      ListNode *result = new ListNode((left->val + 0 + this->andOne) % 10);
      this->andOne = (left->val + 0 + this->andOne) / 10;
      result->next = addTwoNumbers(left->next, NULL);
      return result;
    }

    ListNode *result =
        new ListNode((left->val + right->val + this->andOne) % 10);
    this->andOne = (left->val + right->val + this->andOne) / 10;
    result->next = addTwoNumbers(left->next, right->next);

    return result;
  }
};
