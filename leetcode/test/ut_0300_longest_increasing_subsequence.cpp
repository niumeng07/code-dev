#include <string>
#include <vector>
#include "gtest/gtest.h"
#include "0300_longest_increasing_subsequence/longest_increasing_subsequence.h"

TEST(longest_increasing_subsequence0, test0) {
    vector<int> input({10, 9, 2, 5, 3, 7, 101, 18});
    EXPECT_EQ(Solution().lengthOfLIS(input), 4);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
