#include <iostream>

#include "0206_reverse_list/reverse_list.h"
#include "gtest/gtest.h"

int main(int argc, char **argv) {
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    ReverseList su;
    printList(head);
    ListNode *reversed = su.reverseListBy2(head);
    printList(reversed);
}
