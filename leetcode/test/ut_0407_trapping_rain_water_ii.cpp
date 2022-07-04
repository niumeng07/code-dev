#include <string>
#include <vector>
#include "gtest/gtest.h"
#include "0407_trapping_rain_water_ii/trapping_rain_water_ii.h"

TEST(trapping_rain_water_ii0, test0) {
    vector<vector<int> > input({
            {1, 4, 3, 1, 3, 2},
            {3, 2, 1, 3, 2, 4},
            {2, 3, 3, 2, 3, 1}});
    EXPECT_EQ(Solution().trapRainWater(input), 4);
    vector<vector<int> > input2({/*01 02 03 04 05*/
                                 {3, 3, 3, 3, 3},
                                 /*11 12 13 14 15*/
                                 {3, 2, 2, 2, 3},  // <--
                                 /*21 22 23 24 25*/
                                 {3, 2, 1, 2, 3},
                                 /*31 32 33 34 35*/
                                 {3, 2, 2, 2, 3},
                                 /*41 42 43 44 45*/
                                 {3, 3, 3, 3, 3}});
    EXPECT_EQ(Solution().trapRainWater(input2), 10);
    vector<vector<int> > input3({{2, 3, 3, 2, 3, 1}});
    EXPECT_EQ(Solution().trapRainWater(input3), 0);
    vector<vector<int> > input4({{}});
    EXPECT_EQ(Solution().trapRainWater(input4), 0);
    vector<vector<int> > input5({{1}, {2}});
    EXPECT_EQ(Solution().trapRainWater(input5), 0);
    vector<vector<int> > input6({});
    EXPECT_EQ(Solution().trapRainWater(input6), 0);
    vector<vector<int> > input7{{12, 13, 1, 12},
                                {13, 4, 13, 12},
                                {13, 8, 10, 12},
                                {12, 13, 12, 12},
                                {13, 13, 13, 13}};
    EXPECT_EQ(Solution().trapRainWater(input7), 14);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
