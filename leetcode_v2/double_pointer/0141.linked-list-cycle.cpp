#include "header.h"

class Solution {
  public:
    bool hasCycle(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return false;
        }

        ListNode* fast = head->next;
        ListNode* slow = head;
        while (fast != nullptr && fast->next != nullptr && fast->next->next != nullptr) {
            if (fast == slow) {
                return true;
            }
            fast = fast->next->next;  // 需要判断是否nullptr
            slow = slow->next;
        }
        return false;
    }
};

int main(int argc, char* argv[]) {
    Solution solution;
    solution.hasCycle(nullptr);
    return 0;
}
