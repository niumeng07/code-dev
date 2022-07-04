#include <string>
#include <vector>
#include "gtest/gtest.h"
#include "0221_maximal_square/maximal_square.h"

TEST(maximal_square0, test0) {
    vector<vector<char>> matrix({vector<char>({'1', '0', '1', '0', '0'}),
                                 vector<char>({'1', '0', '1', '1', '1'}),
                                 vector<char>({'1', '1', '1', '1', '1'}),
                                 vector<char>({'1', '0', '0', '1', '0'})});
    EXPECT_EQ(Solution().maximalSquare(matrix), 4);
}
TEST(maximal_square0, test1) {
    vector<vector<char>> matrix({vector<char>({'0', '1'}),
                                 vector<char>({'1', '0'})});
    EXPECT_EQ(Solution().maximalSquare(matrix), 1);
}

TEST(maximal_square0, test2) {
    vector<vector<char>> matrix({vector<char>({'1','1','1','1','0'}),
                                 vector<char>({'1','1','1','1','0'}),
                                 vector<char>({'1','1','1','1','1'}),
                                 vector<char>({'1','1','1','1','1'}),
                                 vector<char>({'0','0','1','1','1'})
                                 });
    EXPECT_EQ(Solution().maximalSquare(matrix), 16);
}
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
