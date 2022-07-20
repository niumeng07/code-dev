#include <iostream>
#include <string>
#include <vector>
#include "gtest/gtest.h"
#include "0225_implement_stack_using_queues/implement_stack_using_queues.h"

TEST(implement_stack_using_queues0, test0) {
    // EXPECT_EQ(Solution().(), );
    MyStack s;
    s.push(1);
    s.push(2);
    cout << s.top() << endl;
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
