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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* pre = nullptr;
        ListNode* left = head;
        ListNode* right = head->next;
        ListNode* next = right->next;
        ListNode* result = right;

        while (right != nullptr && left != nullptr) {
            if (pre) {
                pre->next = right;
            }
            right->next = left;
            left->next = next;  // nullptr

            pre = left;
            left = next;
            if (next == nullptr) {
                break;
            }
            right = next->next;
            if (right == nullptr) {
                break;
            }
            next = right->next;  // nullptr
        }
        return result;
    }
};


int main(int argc, char *argv[]) {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    print_list(head);
    head = Solution().swapPairs(head);
    print_list(head);
    return 0;
}
