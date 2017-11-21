#include "Solution.h"
#include "Solution_B.h"
#include "Solution_Review.h"
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

    cout << "-------------------------------" << endl;
    Node* l = new Node(5);
    Node* r = new Node(5);
    Solution_B sub;
    Node* result2 = sub.addTwoNumbers(l,r);
    printNode(result2);
    cout <<endl;
    cout << "-------------------------Reverse-------------------------" << endl;
    ListNodeR* head = new ListNodeR(4);
    head->next = new ListNodeR(5);
    head->next->next = new ListNodeR(6);
    head->next->next->next = new ListNodeR(7);
    printListR(head);
    ListNodeR* reverse = ReverseList(head);
    cout << "-------------------------Add-------------------------" << endl;
    Solution_Review sur;
    printListR(reverse);
    ListNodeR* left2 = new ListNodeR(5);
    printListR(left2);
    ListNodeR* added = sur.addTwoList(reverse, left2);
    printListR(added);
    return 0;
}
