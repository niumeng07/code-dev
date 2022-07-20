#include <iostream>
#include <string>
#include <vector>
#include "gtest/gtest.h"
#include "1721_swapping_nodes_in_a_linked_list/swapping_nodes_in_a_linked_list.h"

void printList(ListNode* head) {
    ListNode* iter = head;
    while (iter != nullptr) {
        cout << iter->val << ", ";
        iter = iter->next;
    }
    cout << endl;
}

ListNode* buildList(vector<int> nums) {
    if (nums.size() == 0) return nullptr;
    ListNode* head = new ListNode(nums[0]);
    ListNode* iter = head;
    for (int i = 1; i < nums.size(); i++) {
        iter->next = new ListNode(nums[i]);
        iter = iter->next;
    }
    return head;
}

TEST(swapping_nodes_in_a_linked_list0, test0) {
    ListNode* head = buildList({1, 2, 3, 4, 5});
    printList(head);
    Solution().swapNodes(head, 2);
    printList(head);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
