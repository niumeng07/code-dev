#include <Math.h>
#include <gtest/gtest.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  /* 1. 搜索算法
   * 2. 动态规划算法
   *   从第0个数开始, 第0个数计为X
   *   选这个数: 则能获得的最大分数为 f(X) = X + f(1,..., except X-1, X+1)
   *   不选这个数: 则能获得到的最大分数为f(X) = f(1,...
   * */
  vector<int> deleteLeftRight(int value, vector<int> nums) {
    for (vector<int>::iterator iter = nums.begin(); iter < nums.end(); iter++) {
      if (*iter == value)
        nums.erase(iter);
      else
        iter++;
    }
    return nums;
  }
  int maxWithSelectK(int index, vector<int> &nums) {
    int _max = 0;
    for (int i = index; i < nums.size(); i++) {
      _max = max((nums[i] + this->deleteAndEarn(nums[i], nums)),
                 maxWithSelectK(i, nums));
    }
    return _max;
  }
  int deleteAndEarn(int index, vector<int> &nums) {
    int _max = 0;
    _max = this->maxWithSelectK(0, nums);

    return _max;
  }
};

TEST(testCase, test0) {
  Solution su;
  vector<int> input;
  input = {2, 2, 3, 3, 3, 4}; // target=9
  EXPECT_EQ(su.deleteAndEarn(0, input), 9);
}

TEST(testCase, test1) {
  Solution su;
  vector<int> input;
  input = {3, 4, 2}; // target=6
  EXPECT_EQ(su.deleteAndEarn(input), 6);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
