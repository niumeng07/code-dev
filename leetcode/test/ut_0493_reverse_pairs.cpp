#include <string>
#include <vector>
#include "gtest/gtest.h"
#include "0493_reverse_pairs/reverse_pairs.h"

TEST(reverse_pairs0, test0) {
    vector<int> nums({1, 3, 2, 3, 1});
    EXPECT_EQ(Solution().reversePairs(nums), 2);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
