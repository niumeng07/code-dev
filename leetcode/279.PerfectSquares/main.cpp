#include "Solution.h"
#include "gtest/gtest.h"
#include <iostream>
using namespace std;

TEST(testCase, test0) { EXPECT_EQ(0, Solution().process(2)); }
TEST(testCase, test1) { EXPECT_EQ(0, Solution().process(1)); }

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
