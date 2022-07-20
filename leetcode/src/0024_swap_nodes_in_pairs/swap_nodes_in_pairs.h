/*
 * Given a linked list, swap every two adjacent nodes and return its head.
 *
 * You may not modify the values in the list's nodes, only nodes itself may be
 * changed.
 *
 *
 *
 * Example:
 *
 * Given 1->2->3->4, you should return the list as 2->1->4->3.
 */

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr or head->next == nullptr) {
            return head;
        }

        ListNode* last = head;
        ListNode* iter = head->next;
        ListNode* link = iter->next;
        iter->next = last;
        last->next = swapPairs(link);

        return iter;
    }

public:
    // 循环解法
    ListNode* swapPairs2(ListNode* head) {
        ListNode* fakeHead = new ListNode(0);
        fakeHead->next = head;

        // fakeHead(pre), curr, next, nexnex
        ListNode* pre = fakeHead;  // 需要倒序的区间的前序
        ListNode* curr = head;
        // 0   1    2     3       4
        // pre curr next  nexnex
        while (curr && curr->next) {
            // 倒序区间  curr, next
            ListNode* next = curr->next;
            ListNode* nexnex = curr->next->next;  // 需要倒序的区间的后续

            curr->next = nullptr;
            next->next = curr;  // pre ( nullptr <- curr <- next )  nexnex
            // 把区间和前后连起来
            pre->next = next;
            curr->next = nexnex;

            // 重新设置pre, curr
            pre = curr;  // 注意：这里换过位置了,不是pre=next
            curr = nexnex;
        }
        return fakeHead->next;
    }
};
