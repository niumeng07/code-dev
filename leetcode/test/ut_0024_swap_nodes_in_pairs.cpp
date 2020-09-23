#include <iostream>
#include <vector>

#include "0024_swap_nodes_in_pairs/swap_nodes_in_pairs.h"
#include "gtest/gtest.h"

vector<int> printList(ListNode* head) {
    vector<int> res;
    ListNode* iter = head;
    while(iter != nullptr) {
        res.push_back(iter->val);
        iter = iter->next;
    }
    return res;
}

TEST(twosum, test0) {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    EXPECT_EQ(printList(Solution().swapPairs(head)), vector<int>({2, 1}));
}

TEST(twosum, test1) {
    EXPECT_EQ(printList(Solution().swapPairs(nullptr)), vector<int>{});
}

TEST(twosum, test2) {
    ListNode* head = new ListNode(1);
    EXPECT_EQ(printList(Solution().swapPairs(head)), vector<int>({1}));
}

TEST(twosum, test3) {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    EXPECT_EQ(printList(Solution().swapPairs(head)), vector<int>({2, 1, 3}));
}

TEST(twosum, test4) {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    vector<int> excepted;
    EXPECT_EQ(printList(Solution().swapPairs(head)), vector<int>({2, 1, 4, 3}));
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
