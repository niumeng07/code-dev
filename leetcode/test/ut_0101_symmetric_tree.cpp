#include <string>
#include <vector>
#include "gtest/gtest.h"
#include "0101_symmetric_tree/symmetric_tree.h"

TEST(symmetric_tree0, test0) {
    EXPECT_EQ(Solution().isSymmetric(nullptr), true);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
