#include <string>
#include <vector>
#include "gtest/gtest.h"
#include "0031_next_permutation/next_permutation.h"

TEST(next_permutation0, test0) {
    /* 1 2 3
     * 1 3 2   第一个逆序分割为 1 3 和 2
     * 2 1 3   第一个逆序分割为 2 和 1 3
     * 2 3 1
     * 3 1 2
     * 3 2 1
     * */
    vector<int> input{1, 2, 3};
    vector<int> except{1, 3, 2};
    Solution().nextPermutation(input);
    EXPECT_EQ(input, except);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
