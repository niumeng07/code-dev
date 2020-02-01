/**
 * @file FindtheDuplicateNumber.h
 * @brief
 * @author myliuda@sina.com
 * @version 0.0
 * @date 2020-01-28
 */

#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
class FindtheDuplicateNumber {
public:
  /**
   * @brief findSingleNum
   *
   * @param nums
   *
   * @return
   */
  int findSingleNum(vector<int> &nums) {
    int ret = 0;
    for (auto num : nums) {
      ret = ret ^ num;
    }
    return ret;
  }
  /**
   * @brief findDuplicate
   *
   * @param nums
   *
   * @return
   */
  int findDuplicate(vector<int> &nums) {
    for (int num : nums) {
      int index = abs(num) - 1;
      if (nums[index] < 0) {
        return abs(num);
      }
      nums[index] *= -1;
    }

    return -1;
  }
  // 这个方法在数字大于40时就出错了
  int findDuplicate2(vector<int> &nums) {
    uint64_t ret = 0;
    for (auto num : nums) {
      if ((ret & (1 << num)) > 0) {
        ret = num;
        break;
      }
      ret = (ret | (1 << num));
    }
    return ret;
  }
};
