#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};
class ReverseList {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) return head;
        ListNode* iter = head->next;
        head->next = nullptr;
        ListNode* tmp;
        while (iter != nullptr) {
            tmp = iter->next;
            iter->next = head;
            head = iter;
            iter = tmp;
        }
        if (iter == nullptr) iter = head;
        return iter;
    }

    ListNode* reverseList2(ListNode* head) {
        if (head == nullptr) return head;
        ListNode* pre = nullptr;
        ListNode* curr = head;
        //     1    2    3
        // pre curr next temp
        while (curr != nullptr) {
            ListNode* next = curr->next;
            curr->next = pre;
            pre = curr;
            curr = next;
        }
        return pre;
    }

    ListNode* reverseListBy2(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* pre = nullptr;
        ListNode* iter = head;
        ListNode* next = head->next;
        return head;
    }
};

// 1  ->    2
// head
//          iter     tmp

void printList(ListNode* head) {
    ListNode* iter = head;
    while (iter != nullptr) {
        std::cout << iter->val << "\t";
        iter = iter->next;
    }
    cout << endl;
}
