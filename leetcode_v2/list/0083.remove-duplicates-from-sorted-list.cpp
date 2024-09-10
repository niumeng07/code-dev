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

#include "header.h"

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* iter = head;
        while (iter != nullptr && iter->next != nullptr) {
            if (iter->val == iter->next->val) {
                // 需要移除next
                iter->next = iter->next->next;  // 直接指向下下个
            } else {                            // 只有当当前valt 下一个val不相等才会移动
                iter = iter->next;
            }
        }
        return head;
    }
};

int main(int argc, char* argv[]) { 
    //
    return 0;
}
