/**
 * @file FindtheDuplicateNumber.h
 * @author myliuda@sina.com
 * @version 0.0
 * @date 2020-01-28
 * @brief
 *   Given an array nums containing n + 1 integers where each integer is between
 * 1 and n (inclusive), prove that at least one duplicate number must exist.
 *   Assume that there is only one duplicate number, find the duplicate one.
 *
 *   Example 1:
 *
 *   Input: [1,3,4,2,2]
 *   Output: 2
 *   Example 2:
 *
 *   Input: [3,1,3,4,2]
 *   Output: 3
 *   Note:
 *
 *   You must not modify the array (assume the array is read only).
 *   You must use only constant, O(1) extra space.
 *   Your runtime complexity should be less than O(n2).
 *   There is only one duplicate number in the array, but it could be repeated
 *   more than once.
 *
 */

#include <math.h>

#include <iostream>
#include <vector>
using namespace std;
class FindtheDuplicateNumber {
public:
    int findSingleRv(vector<int> &v) {
        vector<int> ret({0, 0, 0, 0, 1, 1, 1, 1});

        for (int i = 0; i < v.size(); i++) {
            ret[0] = ret[0] & v[i];
            ret[1] = ret[1] | v[i];
            ret[2] = ret[2] ^ v[i];
            ret[4] = ret[4] & v[i];
            ret[5] = ret[5] | v[i];
            ret[6] = ret[6] ^ v[i];
        }
        return ret[2];
    }

    int findSingleNum(vector<int> &nums) {
        int ret = 0;
        for (auto num : nums) {
            ret = ret ^ num;
        }
        return ret;
    }
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
