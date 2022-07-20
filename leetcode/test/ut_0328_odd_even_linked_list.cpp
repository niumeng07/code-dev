#include <iostream>
#include <string>
#include <vector>
#include "gtest/gtest.h"
#include "0328_odd_even_linked_list/odd_even_linked_list.h"

TEST(odd_even_linked_list0, test0) {
    ListNode* head = buildList({1,2,3,4});
    printList(head);
    head = Solution().oddEvenList(head);
    printList(head);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
