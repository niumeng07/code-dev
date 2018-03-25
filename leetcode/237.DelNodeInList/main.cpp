#include <iostream>
#include "Solution.h"
using namespace std;

int main() {
    ListNode* node = new ListNode(1);
    node->next = new ListNode(2);
    node->next->next = new ListNode(3);
    ListNode* todel = node->next->next;
    node->next->next->next = new ListNode(4);
    ListNode* iter = node;
    while (iter != NULL) {
        cout << iter->val << ", ";
        iter = iter->next;
    }
    cout << endl;
    Solution su;
    su.deleteNode(todel);
    iter = node;
    while (iter != NULL) {
        cout << iter->val << ", ";
        iter = iter->next;
    }
    cout << endl;
    return 0;
}
