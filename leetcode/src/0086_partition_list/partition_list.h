#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};
class PartitionList {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode left(0), right(0);
        ListNode *l = &left, *r = &right;
        while (head) {
            ListNode*& ref = head->val < x ? l : r;
            ref->next = head;
            ref = ref->next;
            head = head->next;
        }
        l->next = right.next;
        r->next = NULL;
        return left.next;
    }
};
