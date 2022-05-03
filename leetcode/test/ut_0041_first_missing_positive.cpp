#include <time.h>

#include <iostream>
#include <vector>

#include "0041_first_missing_positive/first_missing_positive.h"
#include "gtest/gtest.h"

using namespace std;
TEST(ut_0041_first_missing_positive, test0) {
    vector<int> input{1, 2, 0};
    EXPECT_EQ(Solution().firstMissingPositive(input), 3);
}
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
