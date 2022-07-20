#include <string>
#include <vector>
#include "gtest/gtest.h"
#include "0025_reverse_nodes_in_k_group/reverse_nodes_in_k_group.h"

TEST(reverse_nodes_in_k_group0, test0) {
    EXPECT_EQ(Solution().reverseKGroup(nullptr, 0), nullptr);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
