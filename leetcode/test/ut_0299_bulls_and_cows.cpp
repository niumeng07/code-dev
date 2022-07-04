#include <string>
#include <vector>
#include "gtest/gtest.h"
#include "0299_bulls_and_cows/bulls_and_cows.h"

TEST(bulls_and_cows0, test0) {
    std::string secret = "1807", guess = "7810";
    EXPECT_EQ(Solution().getHint(secret, guess), "1A3B");
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
