#include "gtest/gtest.h"
#include "0206_reverse_list/reverse_list.h"
#include <iostream>

int main() {
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    Solution su;
    printList(head);
    ListNode* reversed = su.reverseList(head);
    printList(reversed);
}
