#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        if (head == nullptr) return head;
        ListNode* iter = head;
        int list_size = 0;
        while (iter != nullptr) {
            list_size++;
            iter = iter->next;
        }
        int back_k = list_size - k - 1;    // 倒数第k个对应正数第back_k个
        if (k == back_k) return head;  //不需要换

        ListNode* dumHead = new ListNode(-1);
        dumHead->next = head;
        // 找第k个结点、前序节点、后序节点
        // 找第back_k个结点、前序节点、后序节点
        iter = head;
        int idx = 0;
        ListNode* left = head;
        ListNode* left_pre = dumHead;
        ListNode* left_suff = nullptr;
        ListNode* right = head;
        ListNode* right_pre = dumHead;
        ListNode* right_suff = nullptr;
        while (iter != nullptr) {
            if (idx == k - 1) {
                left_pre = iter;
            }
            if (idx == k) {
                left = iter;
            }
            if (idx == k + 1) {
                left_suff = iter;
            }
            if (idx == back_k - 1) {
                right_pre = iter;
            }
            if (idx == back_k) {
                right = iter;
            }
            if (idx == back_k + 1) {
                right_suff = iter;
            }
            iter = iter->next;
            idx++;
        }
        // left_pre, left, left_suff, right_pre, right, right_suff
        if (left != nullptr && right != nullptr && left->next != right &&
            right->next != left) {  // 不相邻
            if (left_pre != nullptr) left_pre->next = right;
            if (right_pre != nullptr) right_pre->next = left;
            right->next = left_suff;
            left->next = right_suff;
        } else if (left != nullptr && right != nullptr) {
            // 相邻
            left_pre->next = right;
            right->next = left;
            left->next = right_suff;
        }
        return dumHead->next;
    }
};
