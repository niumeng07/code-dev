#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* BuildList(vector<int> values) {
    if (values.empty()) return nullptr;
    ListNode* head = new ListNode(values[0]);
    ListNode* iter = head;
    for (int i = 1; i < values.size(); i++) {
        iter->next = new ListNode(values[i]);
        iter = iter->next;
    }
    return head;
}
void PrintList(ListNode* head) {
    ListNode* iter = head;
    while (iter != nullptr) {
        cout << iter->val << ", ";
        iter = iter->next;
    }
    cout << endl;
}

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* iter1 = list1;
        ListNode* iter2 = list2;
        if (iter1 == nullptr) return iter2;
        if (iter2 == nullptr) return iter1;
        ListNode* out = nullptr;
        if (iter1->val < iter2->val) {
            out = iter1;
            iter1 = iter1->next;
        } else {
            out = iter2;
            iter2 = iter2->next;
        }
        while (iter1 != nullptr && iter2 != nullptr) {
            if (iter1->val < iter2->val) {
                out->next = iter1;
                out = out->next;
                iter1 = iter1->next;
            } else {
                out->next = iter2;
                out = out->next;
                iter2 = iter2->next;
            }
        }
        if (iter1 != nullptr) {
            out->next = iter1;
        }
        if (iter2 != nullptr) {
            out->next = iter2;
        }
        return out;
    }
};
