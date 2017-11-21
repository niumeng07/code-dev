#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* end = head;
        while(end->next != NULL)
            end = end->next;
        for(ListNode* iter = head; iter!=end; iter=iter->next)
        {
        }
        return head;
    }
};
