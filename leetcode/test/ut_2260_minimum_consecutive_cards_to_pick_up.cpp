#include <string>
#include <vector>
#include "gtest/gtest.h"
#include "2260_minimum_consecutive_cards_to_pick_up/minimum_consecutive_cards_to_pick_up.h"

TEST(minimum_consecutive_cards_to_pick_up0, test0) {
    vector<int> cards({3, 4, 2, 3, 4, 7});
    EXPECT_EQ(Solution().minimumCardPickup(cards), 4);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
