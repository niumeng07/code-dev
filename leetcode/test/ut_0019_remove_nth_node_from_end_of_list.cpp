#include "gtest/gtest.h"
#include <string>
#include <vector>
#include "0019_remove_nth_node_from_end_of_list/remove_nth_node_from_end_of_list.h"

void printList(ListNode* head) {
    ListNode* iter = head;
    while(iter!=nullptr) {
        cout << iter->val << ", ";
        iter = iter->next;
    }
    cout << endl;
}

TEST(remove_nth_node_from_end_of_list0, test0) {
    ListNode* head = new ListNode(0);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    ListNode* output = Solution().removeNthFromEnd(head, 0);
    printList(output);
}

TEST(remove_nth_node_from_end_of_list0, test1) {
    ListNode* head = new ListNode(0);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    ListNode* output = Solution().removeNthFromEnd(head, 1);
    printList(output);
}

TEST(remove_nth_node_from_end_of_list0, test2) {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    ListNode* output = Solution().removeNthFromEnd(head, 2);
    printList(output);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
