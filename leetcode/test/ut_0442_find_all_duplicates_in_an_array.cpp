#include <string>
#include <vector>

#include "0442_find_all_duplicates_in_an_array/find_all_duplicates_in_an_array.h"
#include "gtest/gtest.h"

TEST(find_all_duplicates_in_an_array0, test0) {
    // vector<int> nums({1, 2, 2, 3, 4, 4});
    // EXPECT_EQ(Solution().findDuplicates(nums), vector({2, 4}));
    vector<int> nums1({4, 3, 2, 7, 8, 2, 3, 1});
    EXPECT_EQ(Solution().findDuplicates(nums1), vector({2, 3}));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
