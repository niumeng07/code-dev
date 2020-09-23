#include <iostream>
using namespace std;

/* Given a linked list, remove the n-th node from the end of list and return its
 * head.
 * 
 * Example:
 * 
 * Given linked list: 1->2->3->4->5, and n = 2.
 * 
 * After removing the second node from the end, the linked list becomes 1->2->3->5.
 * Note:
 * 
 * Given n will always be valid.
 * 
 * Follow up:
 * 
 * Could you do this in one pass?
 * */
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (n <= 0) return head;
        ListNode* iter = head;
        ListNode* preDel = nullptr;
        ListNode* toDel = head;
        int i = 1;
        while (i < n) {
            if (iter->next == nullptr) return head;
            i++;
            iter = iter->next;
        }
        while (iter->next != nullptr) {
            iter = iter->next;
            preDel = toDel;
            toDel = toDel->next;
        }
        // toDel will be deleted.
        if (preDel == nullptr) {
            head = head->next;
            return head;
        }
        preDel->next = toDel->next;
        return head;
    }
};
