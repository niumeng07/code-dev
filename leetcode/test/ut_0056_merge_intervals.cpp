#include <string>
#include <vector>
#include "gtest/gtest.h"
#include "0056_merge_intervals/merge_intervals.h"

TEST(merge_intervals0, test0) {
    vector<vector<int>> intervals({{1, 3}, {2, 6}, {8, 10}, {15, 18}});
    EXPECT_EQ(Solution().merge(intervals),
              vector<vector<int>>({{1, 6}, {8, 10}, {15, 18}}));
    intervals = {};
    EXPECT_EQ(Solution().merge(intervals), vector<vector<int>>({}));
    intervals = {vector<int>({1, 4}), vector<int>({4, 5})};
    EXPECT_EQ(Solution().merge(intervals), vector<vector<int>>({{1, 5}}));
    intervals = {vector<int>({1, 4}), vector<int>({2, 3})};
    EXPECT_EQ(Solution().merge(intervals), vector<vector<int>>({{1, 4}}));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
