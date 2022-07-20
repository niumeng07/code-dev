#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* buildList(vector<int> nums) { if (nums.size() == 0) return nullptr;
    ListNode* head = new ListNode(nums[0]);
    ListNode* iter = head;
    for (int i = 1; i < nums.size(); i++) {
        iter->next = new ListNode(nums[i]);
        iter = iter->next;
    }
    return head;
}

void printList(ListNode* head) {
    ListNode* iter = head;
    while (iter != nullptr) {
        cout << iter->val << ", ";
        iter = iter->next;
    }
    cout << endl;
}

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        // 1    2     3    4   |  5
        // odd, even, odd, even|  odd
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* odditer = head;
        ListNode* eveniter = even;
        while (odditer->next->next != nullptr && eveniter->next->next != nullptr) {
            odditer->next = odditer->next->next;
            eveniter->next = eveniter->next->next;
            odditer = odditer->next;
            eveniter = eveniter->next;
        }
        if (eveniter->next != nullptr) { // 最后一个node是odd,需要特殊处理
            odditer->next = odditer->next->next;
            odditer = odditer->next;
            eveniter->next = nullptr;
        }
        odditer->next = even;
        return odd;
    }
};
