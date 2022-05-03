#include <string>
#include <vector>

#include "0021_merge_two_sorted_lists/merge_two_sorted_lists.h"
#include "gtest/gtest.h"

TEST(merge_two_sorted_lists0, test0) {
    ListNode* list1 = BuildList({1, 2, 4});
    ListNode* list2 = BuildList({1, 3, 4});
    ListNode* list3 = BuildList({1, 1, 2, 3, 4, 4});
    PrintList(list1);
    PrintList(list2);
    PrintList(list3);
    // EXPECT_EQ(Solution().mergeTwoLists(list1, list2), list3);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
