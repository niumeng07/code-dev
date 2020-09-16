#include <iostream>

#include "0002_add_two_number/add_two_number.h"
#include "gtest/gtest.h"

TEST(add_two_number, test0) {
    ListNode *left = new ListNode(5);
    ListNode *tmp = left;

    ListNode *right = new ListNode(5);
    tmp = right;

    AddTwoNumber su;
    ListNode *result = su.addTwoNumbers(left, right);
}
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
