#include <string>
#include <vector>
#include "gtest/gtest.h"
#include "0274_h-index/h-index.h"

TEST(h_index0, test0) {
    vector<int> citations({3, 0, 6, 1, 5});
    EXPECT_EQ(Solution().hIndex(citations), 3);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
