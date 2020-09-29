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

vector<int> list2vector(ListNode* input) {
    vector<int> res;
    ListNode* iter = input;
    while(iter != nullptr) {
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

vector<ListNode*> list2vector2(ListNode* head) {
    vector<ListNode*> res;
    ListNode* iter = head;
    while(iter != nullptr) {
        res.push_back(iter);
        iter = iter->next;
    }
    return res;
}

ListNode* vector2list2(const vector<ListNode*> input) {
    if (input.empty()) return nullptr;
    ListNode* res = input[0];
    ListNode* iter = res;
    for (int i = 1; i < input.size(); i++) {
        iter->next = input[i];
        iter = iter->next;
    }
    return res;
}

bool comp(ListNode* lhs, ListNode* rhs) {
    return lhs->val < rhs->val;
}

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        vector<int> v = list2vector(head);
        std::sort(v.begin(), v.end());
        return vector2list(v);
    }
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        vector<ListNode*> v = list2vector2(head);
        std::sort(v.begin(), v.end(), comp);
        return vector2list2(v);
    }
};
