#include <string>
#include <vector>
#include "gtest/gtest.h"
#include "0698_partition_to_k_equal_sum_subsets/partition_to_k_equal_sum_subsets.h"

TEST(partition_to_k_equal_sum_subsets0, test0) {
    vector<int> nums({4, 5, 3, 2, 3, 1});
    EXPECT_EQ(Solution().canPartitionKSubsets(nums, 3), true);
    // vector<int> nums2({7628, 3147, 7137, 2578, 7742, 2746, 4264, 7704, 9532,
    //                    9679, 8963, 3223, 2133, 7792, 5911, 3979});
    // EXPECT_EQ(Solution().canPartitionKSubsets(nums2, 6), false);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
