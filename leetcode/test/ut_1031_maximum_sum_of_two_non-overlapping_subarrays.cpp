#include <string>
#include <vector>
#include "gtest/gtest.h"
#include "1031_maximum_sum_of_two_non-overlapping_subarrays/maximum_sum_of_two_non-overlapping_subarrays.h"

TEST(maximum_sum_of_two_non_overlapping_subarrays0, test0) {
    vector<int> nums({});
    EXPECT_EQ(Solution().maxSumTwoNoOverlap(nums, 0, 0), 0);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
