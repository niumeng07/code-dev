#include <iostream>
#include <vector>

#include "0240_search_a_2d_matrix_ii/search_a_2d_matrix_ii.h"
#include "gtest/gtest.h"

using namespace std;

TEST(search_a_2d_matrix_ii, test1) {
    vector<vector<int> > matrix{{1, 2, 3}, {4, 5, 6}};
    EXPECT_EQ(Solution().searchMatrix(matrix, 1), true);
    EXPECT_EQ(Solution().searchMatrix(matrix, 2), true);
    EXPECT_EQ(Solution().searchMatrix(matrix, 3), true);
    EXPECT_EQ(Solution().searchMatrix(matrix, 4), true);
    EXPECT_EQ(Solution().searchMatrix(matrix, 5), true);
    EXPECT_EQ(Solution().searchMatrix(matrix, 6), true);
    EXPECT_EQ(Solution().searchMatrix(matrix, 8), false);
    EXPECT_EQ(Solution().searchMatrix(matrix, 0), false);

    vector<vector<int> > matrix2({{1, 4, 7, 11, 15},
                                  {2, 5, 8, 12, 19},
                                  {3, 6, 9, 16, 22},
                                  {10, 13, 14, 17, 24},
                                  {18, 21, 23, 26, 30}});
    EXPECT_EQ(Solution().searchMatrix(matrix2, 5), true);

    vector<vector<int> > matrix3({{}});
    EXPECT_EQ(Solution().searchMatrix(matrix3, 0), false);

    vector<vector<int> > matrix4({{1}});
    EXPECT_EQ(Solution().searchMatrix(matrix4, 0), false);
    EXPECT_EQ(Solution().searchMatrix(matrix4, 1), true);
    EXPECT_EQ(Solution().searchMatrix(matrix4, 3), false);

    vector<vector<int> > matrix5({{1, 2, 3, 4, 5},
                                  {6, 7, 8, 9, 10},
                                  {11, 12, 13, 14, 15},
                                  {16, 17, 18, 19, 20},
                                  {21, 22, 23, 24, 25}});
    EXPECT_EQ(Solution().searchMatrix(matrix5, 5), true);
}

TEST(search_a_2d_matrix_ii, test2) {
    vector<vector<int> > matrix{{1, 2, 3}, {4, 5, 6}};
    EXPECT_EQ(Solution().searchMatrixMN(matrix, 1), true);
    EXPECT_EQ(Solution().searchMatrixMN(matrix, 2), true);
    EXPECT_EQ(Solution().searchMatrixMN(matrix, 3), true);
    EXPECT_EQ(Solution().searchMatrixMN(matrix, 4), true);
    EXPECT_EQ(Solution().searchMatrixMN(matrix, 5), true);
    EXPECT_EQ(Solution().searchMatrixMN(matrix, 6), true);
    EXPECT_EQ(Solution().searchMatrixMN(matrix, 8), false);
    EXPECT_EQ(Solution().searchMatrixMN(matrix, 0), false);

    vector<vector<int> > matrix2({{1, 4, 7, 11, 15},
                                  {2, 5, 8, 12, 19},
                                  {3, 6, 9, 16, 22},
                                  {10, 13, 14, 17, 24},
                                  {18, 21, 23, 26, 30}});
    EXPECT_EQ(Solution().searchMatrixMN(matrix2, 5), true);

    vector<vector<int> > matrix3({{}});
    EXPECT_EQ(Solution().searchMatrixMN(matrix3, 0), false);

    vector<vector<int> > matrix4({{1}});
    EXPECT_EQ(Solution().searchMatrixMN(matrix4, 0), false);
    EXPECT_EQ(Solution().searchMatrixMN(matrix4, 1), true);
    EXPECT_EQ(Solution().searchMatrixMN(matrix4, 3), false);

    vector<vector<int> > matrix5({{1, 2, 3, 4, 5},
                                  {6, 7, 8, 9, 10},
                                  {11, 12, 13, 14, 15},
                                  {16, 17, 18, 19, 20},
                                  {21, 22, 23, 24, 25}});
    EXPECT_EQ(Solution().searchMatrixMN(matrix5, 5), true);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
