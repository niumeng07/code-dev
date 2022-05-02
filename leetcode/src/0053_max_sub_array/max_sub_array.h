/**
 * @brief
 * Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
 * 整数列表,找连续subarray,有最大和的
 * 
 * A subarray is a contiguous part of an array.
 * 
 * Example 1:
 *   Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
 *   Output: 6
 *   Explanation: [4,-1,2,1] has the largest sum = 6.
 * 
 * Example 2:
 *   Input: nums = [1]
 *   Output: 1
 * 
 * Example 3:
 *   Input: nums = [5,4,-1,7,8]
 *   Output: 23
 */
#include <vector>
using namespace std;
class MaxSubArray {
public:
    int process(vector<int>& nums, int curr_pos) {
        if (curr_pos == nums.size()) return 0;
        if (nums[curr_pos] > 0)
            m = (nums[curr_pos] + process(nums, curr_pos + 1)) > m
                        ? (nums[curr_pos] + process(nums, curr_pos + 1))
                        : m;
        else
            m = process(nums, curr_pos + 1) > m ? process(nums, curr_pos + 1)
                                                : m;
        return m;
    }
    int maxSubArray(vector<int>& nums) { return process(nums, 0); }

public:
    int m = 0;
};
