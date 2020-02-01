#include "0001_two_sum/two_sum.h"
#include "gtest/gtest.h"
#include <iostream>
#include <vector>

TEST(twosum, test0) {
  std::vector<int> v = {2, 7, 11, 15};
  std::vector<int> r = {0, 1};
  EXPECT_EQ(TwoSum().twoSum(v, 9), r);
}

TEST(twosum, test1) {
  std::vector<int> v = {2, 7, 11, 15};
  std::vector<int> r = {0, 2};
  EXPECT_EQ(TwoSum().twoSum(v, 13), r);
}

TEST(twosum, test2) {
  std::vector<int> v = {2, 7, 11, 15};
  std::vector<int> r = {0, 3};
  EXPECT_EQ(TwoSum().twoSum(v, 17), r);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
