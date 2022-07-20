#include <string>
#include <vector>
#include "gtest/gtest.h"
#include "1031_maximum_sum_of_two_non-overlapping_subarrays/maximum_sum_of_two_non-overlapping_subarrays.h"

TEST(maximum_sum_of_two_non_overlapping_subarrays0, test0) {
    vector<int> nums({0, 6, 5, 2, 2, 5, 1, 9, 4});
    EXPECT_EQ(Solution().maxSumTwoNoOverlap(nums, 1, 2), 20);
}

TEST(maximum_sum_of_two_non_overlapping_subarrays0, test1) {
    vector<int> nums({0, 6, 5, 2, 2, 5, 1, 9, 4});
    EXPECT_EQ(Solution1().maxSumTwoNoOverlap(nums, 1, 2), 20);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
