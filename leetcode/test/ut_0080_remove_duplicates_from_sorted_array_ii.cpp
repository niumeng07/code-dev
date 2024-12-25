#include <string>
#include <vector>
#include "gtest/gtest.h"
#include "0080_remove_duplicates_from_sorted_array_ii/remove_duplicates_from_sorted_array_ii.h"

TEST(remove_duplicates_from_sorted_array_ii0, test0) {
    vector<int> nums({1, 1, 1, 1});
    EXPECT_EQ(Solution().removeDuplicates(nums), 2);
}
TEST(remove_duplicates_from_sorted_array_ii0, test1) {
    vector<int> nums({1,1,1,2,2,2,3});
    EXPECT_EQ(Solution().removeDuplicates(nums), 5);
}
TEST(remove_duplicates_from_sorted_array_ii0, test2) {
    vector<int> nums({0,0,1,1,1,1,2,3,3});
    EXPECT_EQ(Solution().removeDuplicates(nums), 7);
}
TEST(remove_duplicates_from_sorted_array_ii0, test3) {
    vector<int> nums({0,0,1,1,1,1,2,3,3});
    EXPECT_EQ(Solution().removeDuplicates(nums), 7);
}

TEST(remove_duplicates_from_sorted_array_ii0, test4) {
    vector<int> nums({0,0,1,1,1,1,2,2,2,4});
    EXPECT_EQ(Solution().removeDuplicates(nums), 7);
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
