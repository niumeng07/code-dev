#include <string>
#include <vector>
#include "gtest/gtest.h"
#include "1423_maximum_points_you_can_obtain_from_cards/maximum_points_you_can_obtain_from_cards.h"

TEST(maximum_points_you_can_obtain_from_cards0, test0) {
    vector<int> cardPoints({1, 2, 3, 4, 5, 6, 1});
    EXPECT_EQ(Solution().maxScore(cardPoints, 3), 12);
    vector<int> cardPoints2({2, 2, 2});
    EXPECT_EQ(Solution().maxScore(cardPoints2, 2), 4);
    vector<int> cardPoints3({9, 7, 7, 9, 7, 7, 9});
    EXPECT_EQ(Solution().maxScore(cardPoints3, 7), 55);
    vector<int> cardPoints4({1, 1000, 1});
    EXPECT_EQ(Solution().maxScore(cardPoints4, 1), 1);
    vector<int> cardPoints5({1, 79, 80, 1, 1, 1, 200, 1});
    EXPECT_EQ(Solution().maxScore(cardPoints5, 3), 202);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
