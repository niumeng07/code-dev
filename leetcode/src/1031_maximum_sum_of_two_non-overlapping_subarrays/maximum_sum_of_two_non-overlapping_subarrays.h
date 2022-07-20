#include <iostream>
#include <functional>
#include <numeric>
#include <vector>
using namespace std;

/*
 * 给出非负整数数组 nums,
 * 返回两个非重叠(连续)子数组中元素的最大和, 子数组的长度分别为 firstLen 和 secondLen.
 * (这里需要澄清的是, 长为 firstLen 的子数组可以出现在长为 secondLen 的子数组之前或之后. )
 * 从形式上看, 返回最大的 V
 * 而 V = (nums[i] + nums[i+1] + ... + nums[i+firstLen-1]) + (nums[j] + nums[j+1] + ... + nums[j+secondLen-1])
 * 并满足下列条件之一:
 * 0 <= i < i + firstLen - 1 < j < j + secondLen - 1 < nums.length,
 * 或 0 <= j < j + secondLen - 1 < i < i + firstLen - 1 < nums.length.
 */

// Version: 1
// 耗时有优化空间: 每次重新计算max
class Solution {
public:
    // 从start(含)到end(含)中选连续的k个数,和最大
    int findMaxSumIn(vector<int>& nums, int start, int end, int k) {
        if (end - start + 1 < k) return 0;
        int sumK = 0;
        for (int i = start; i < start + k; i++) {  // 前k个
            sumK += nums[i];
        }
        int value = sumK;
        for (int i = start + k; i <= end; i++) {
            sumK = sumK + nums[i] - nums[i - k];
            value = max(value, sumK);
        }
        return value;
    }
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        /* 方法一
         * 滑动窗口遍历firstLen子串的所有可能情况
         * 从剩余的left,right两段中搜索secondLen子串
         * */
        /* 方法二,动态规划
         * 找一个下标把数组分成两边,两个子数据各在其中一部分
         * */
        int size = nums.size();
        if (firstLen + secondLen > size) return 0;
        int value = 0;
        for (int i = 0; i <= size; i++) {
            int left = 0;
            int right = 0;
            if (i - 0 >= firstLen && size - i >= secondLen) {
                left = findMaxSumIn(nums, 0, i - 1, firstLen);
                right = findMaxSumIn(nums, i, size - 1, secondLen);
                value = max(value, left + right);
            }
            if (i - 0 >= secondLen && size - i >= firstLen) {
                left = findMaxSumIn(nums, 0, i - 1, secondLen);  // secondLen=2
                right = findMaxSumIn(nums, i, size - 1,
                                     firstLen);  // firstLen=1
                value = max(value, left + right);
            }
        }
        return value;
    }
};
// 优化方案
/* 方案1. 分为两段, 左右各维护一个最大堆(也可以各维护两个最大堆)
 * 方案2. DP
 * */
class Solution1 {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        //计算dp, 4个滑动窗口, 4种情况
        vector<vector<int>> dp(nums.size(), vector<int>(4, 0));
        int presum = 0;
        int maxsum;
        for (int i = 0; i < firstLen; ++i) {
            presum += nums[i];
        }
        maxsum = presum;
        dp[firstLen - 1][0] = maxsum;
        for (int i = firstLen; i < nums.size(); ++i) {
            presum -= nums[i - firstLen];
            presum += nums[i];
            maxsum = max(maxsum, presum);
            dp[i][0] = maxsum;
        }

        presum = 0;
        for (int i = 0; i < secondLen; ++i) {
            presum += nums[i];
        }
        maxsum = presum;
        dp[secondLen - 1][1] = maxsum;
        for (int i = secondLen; i < nums.size(); ++i) {
            presum -= nums[i - secondLen];
            presum += nums[i];
            maxsum = max(maxsum, presum);
            dp[i][1] = maxsum;
        }

        presum = 0;
        for (int i = nums.size() - 1; i >= nums.size() - firstLen; --i) {
            presum += nums[i];
        }
        maxsum = presum;
        dp[nums.size() - firstLen][2] = maxsum;
        for (int i = nums.size() - firstLen - 1; i >= 0; --i) {
            presum -= nums[i + firstLen];
            presum += nums[i];
            maxsum = max(maxsum, presum);
            dp[i][2] = maxsum;
        }

        presum = 0;
        for (int i = nums.size() - 1; i >= nums.size() - secondLen; --i) {
            presum += nums[i];
        }
        maxsum = presum;
        dp[nums.size() - secondLen][3] = maxsum;
        for (int i = nums.size() - secondLen - 1; i >= 0; --i) {
            presum -= nums[i + secondLen];
            presum += nums[i];
            maxsum = max(maxsum, presum);
            dp[i][3] = maxsum;
        }

        //计算答案
        int res = 0;
        // firstLen在secondLen左边
        for (int i = firstLen; i <= nums.size() - secondLen; ++i)
            res = max(res, dp[i - 1][0] + dp[i][3]);
        // secondLen在firstLen左边
        for (int i = secondLen; i <= nums.size() - firstLen; ++i)
            res = max(res, dp[i - 1][1] + dp[i][2]);

        return res;
    }
};

