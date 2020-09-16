#include "0240_search_a_2d_matrix_ii/search_a_2d_matrix_ii.h"
#include "gtest/gtest.h"
#include <iostream>
#include <vector>

using namespace std;

TEST(search_a_2d_matrix_ii, test1) {
    vector<vector<int> > matrix;
    matrix.push_back({1,2,3});
    matrix.push_back({4,5,6});
    EXPECT_EQ(Solution().searchMatrix(matrix, 1), true);
    EXPECT_EQ(Solution().searchMatrix(matrix, 8), false);
    vector<vector<int> > matrix2({{1, 4, 7, 11, 15},
                                  {2, 5, 8, 12, 19},
                                  {3, 6, 9, 16, 22},
                                  {10, 13, 14, 17, 24},
                                  {18, 21, 23, 26, 30}});
    EXPECT_EQ(Solution().searchMatrix(matrix2, 5), true);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
