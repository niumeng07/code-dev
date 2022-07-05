#include <string>
#include <vector>
#include "gtest/gtest.h"
#include "0263_ugly_number/ugly_number.h"

TEST(ugly_number0, test0) {
    EXPECT_EQ(Solution().(), );
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
