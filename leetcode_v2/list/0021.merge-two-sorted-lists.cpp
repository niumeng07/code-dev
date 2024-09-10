#include "header.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = new ListNode(0);
        ListNode* iter = head;
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                iter->next = list1;
                list1 = list1->next;
                iter = iter->next;
            } else {
                iter->next = list2;
                list2 = list2->next;
                iter = iter->next;
            }
        }
        while (list2 != nullptr) {
            iter->next = list2;
            list2 = list2->next;
            iter = iter->next;
        }
        while (list1 != nullptr) {
            iter->next = list1;
            list1 = list1->next;
            iter = iter->next;
        }
        return head->next;
    }
};

int main(int argc, char *argv[])
{
    
    return 0;
}
