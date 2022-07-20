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
    vector<ListNode*> reverseListPart(ListNode* start, ListNode* end) {
        ListNode* prev = end->next;
        ListNode* p = start;
        while (prev != end) {
            ListNode* nex = p->next;
            p->next = prev;
            prev = p;
            p = nex;
        }
        ListNode* temp = start;
        start = end;
        end = temp;
        // cout << "part新的start:" << start->value << ", 新的end:" <<
        // end->value << endl;
        return vector<ListNode*>({start, end});
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dum = new ListNode(0);
        dum->next = head;
        ListNode* start = nullptr;
        ListNode* end = dum;
        k--;
        while (end->next != nullptr) {
            // 重新较正start, end
            ListNode* pre = end;
            start = end->next;
            end = start;

            int i = 0;  // 数个数k个
            while (i < k && end->next != nullptr) {
                end = end->next;
                i++;
            }
            if (i < k) {  // 不足k个,不操作(也可以操作)
                break;
            }
            ListNode* next = end->next;
            // 把start到end的反转,返回新的start和end
            auto startendnew = reverseListPart(start, end);
            start = startendnew[0];
            end = startendnew[1];
            // pre->next = 新的start
            pre->next = start;
            // 新的end->next = next;
            end->next = next;
        }
        return dum->next;
    }
};
