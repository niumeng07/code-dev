#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class ReverseList {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL)
            return head;
        ListNode* iter = head->next;
        head->next = NULL;
        ListNode* tmp;
        while(iter != NULL) {
            tmp = iter->next;
            iter->next = head;
            head = iter;
            iter = tmp;
        }
        if(iter == NULL)
            iter = head;
        return iter;
    }
};

// 1  ->    2
// head
//          iter     tmp

void printList(ListNode* head) {
    ListNode* iter = head;
    while(iter != NULL) {
        std::cout << iter->val << "\t";
        iter = iter->next;
    }
    cout << endl;
}
