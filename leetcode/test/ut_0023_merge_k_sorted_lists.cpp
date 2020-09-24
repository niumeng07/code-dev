#include "gtest/gtest.h"
#include <string>
#include <vector>
#include "0023_merge_k_sorted_lists/merge_k_sorted_lists.h"

void printList(ListNode* head) {
    ListNode* iter = head;
    while (iter != nullptr) {
        cout << iter->val << ", ";
        iter = iter->next;
    }
    cout << endl;
}
TEST(merge_k_sorted_lists0, test0) {
    vector<ListNode*> vec;
    for (int i = 0; i < 10; i++) {
        ListNode* head = new ListNode(i);
        head->next = new ListNode(i + 3);
        head->next->next = new ListNode(i + 5);
        vec.push_back(head);
    }
    ListNode* res = Solution().mergeKLists(vec);
    printList(res);
}

TEST(merge_k_sorted_lists0, test1) {
    vector<ListNode*> vec;
    for (int i = 0; i < 10; i++) {
        ListNode* head = nullptr;
        vec.push_back(head);
    }
    ListNode* res = Solution().mergeKLists(vec);
    printList(res);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
