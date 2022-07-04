#include <string>
#include <vector>
#include "gtest/gtest.h"
#include "0045_jump_game_ii/jump_game_ii.h"

TEST(jump_game_ii0, test0) {
    vector<int> nums({2, 3, 1, 1, 4});
    EXPECT_EQ(Solution().jump(nums), 2);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
