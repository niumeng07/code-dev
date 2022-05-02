#include <iostream>
#include <vector>
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
    ListNode* merge(ListNode* a, ListNode* b) {
        if (a == nullptr) return b;
        if (b == nullptr) return a;
        ListNode* c;
        if (a->val < b->val) {
            c = a;
            c->next = merge(a->next, b);
        } else {
            c = b;
            c->next = merge(a, b->next);
        }
        return c;
    }
    ListNode* midpoint(ListNode* head) {
        ListNode* fast = head->next;
        ListNode* slow = head;
        while (fast and fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* mid = midpoint(head);
        ListNode* a = head;
        ListNode* b = mid->next;
        mid->next = nullptr;
        a = sortList(a);
        b = sortList(b);
        ListNode* c = merge(a, b);
        return c;
    }
};

vector<int> list2vector(ListNode* input) {
    vector<int> res;
    ListNode* iter = input;
    while (iter != nullptr) {
        res.push_back(iter->val);
        iter = iter->next;
    }
    return res;
}

ListNode* vector2list(const vector<int> input) {
    if (input.empty()) return nullptr;
    ListNode* res = new ListNode(input[0]);
    ListNode* iter = res;
    for (int i = 1; i < input.size(); i++) {
        iter->next = new ListNode(input[i]);
        iter = iter->next;
    }
    return res;
}
