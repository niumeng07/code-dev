#include <string>
#include <vector>
#include "gtest/gtest.h"
#include "0148_sort_list/sort_list.h"

TEST(sort_list0, test0) {
    EXPECT_EQ(list2vector(Solution().sortList(vector2list({2, 1, 3, 4}))),
              vector<int>({1, 2, 3, 4}));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
