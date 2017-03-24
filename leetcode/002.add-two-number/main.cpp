#include "Solution.h"
#include <iostream>

int main()
{
    ListNode *left = new ListNode(5);
    ListNode *tmp = left;

    ListNode *right = new ListNode(5);
    tmp = right;

    left->print();
    right->print();
    Solution su;
    ListNode* result = su.addTwoNumbers(left, right);
    result->print();

    return 0;
}
