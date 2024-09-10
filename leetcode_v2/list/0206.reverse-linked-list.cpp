#include "header.h"

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        // curr next  nn
        // 1    2     3      4
        ListNode* curr = head;
        ListNode* next = curr->next;
        curr->next = nullptr;  // 打断最开始的这个指针,否则会在反转后循环
        ListNode* tmp = nullptr;
        while (next != nullptr) {
            tmp = next->next;
            next->next = curr;
            curr = next;
            next = tmp;
        }
        return curr;
    }
};

void print_list(ListNode* head) {
    ListNode* iter = head;
    while (iter != nullptr) {
        cout << iter->val << " ";
        iter = iter->next;
    }
    cout << endl;
}
int main(int argc, char* argv[]) {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    print_list(head);
    head = Solution().reverseList(head);
    print_list(head);
    return 0;
}
