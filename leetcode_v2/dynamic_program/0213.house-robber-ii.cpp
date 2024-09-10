/*
 * 你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都 围成一圈
 * ，这意味着第一个房屋和最后一个房屋是紧挨着的。同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警
 * 。
 *
 * 给定一个代表每个房屋存放金额的非负整数数组，计算你 在不触动警报装置的情况下 ，今晚能够偷窃到的最高金额。
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums = [2,3,2]
 * 输出：3
 * 解释：你不能先偷窃 1 号房屋（金额 = 2），然后偷窃 3 号房屋（金额 = 2）, 因为他们是相邻的。
 * 示例 2：
 *
 * 输入：nums = [1,2,3,1]
 * 输出：4
 * 解释：你可以先偷窃 1 号房屋（金额 = 1），然后偷窃 3 号房屋（金额 = 3）。
 *      偷窃到的最高金额 = 1 + 3 = 4 。
 * 示例 3：
 *
 * 输入：nums = [1,2,3]
 * 输出：3
 * */

#include "header.h"

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        } else if (nums.size() == 1) {
            return nums[0];
        } else if (nums.size() == 2) {
            return max(nums[0], nums[1]);
        }

        // 至少有三间
        // 先把第一间置0，其它按原方法计算，得到结果dp[n]和dp[n-1]
        vector<int> dp1 = {nums[0], nums[0]};  // rob no.1
        vector<int> dp2 = {0, nums[1]};        // ~rob no.1
        for (size_t i = 2; i < nums.size() - 1; i++) {
            dp1.push_back(max(dp1[i - 2] + nums[i], dp1[i - 1]));
        }
        for (size_t i = 2; i < nums.size(); i++) {
            dp2.push_back(max(dp2[i - 2] + nums[i], dp2[i - 1]));
        }
        return max(dp1.back(), dp2.back());
    }
};

int main(int argc, char* argv[]) {
    vector<int> nums = {2, 3, 2};
    cout << Solution().rob(nums) << " 3" << endl;

    nums = {1, 2, 3, 1};
    cout << Solution().rob(nums) << " 4" << endl;

    nums = {1, 2, 3};
    cout << Solution().rob(nums) << " 3" << endl;

    nums = {4, 1, 2, 7, 5, 3, 1};
    cout << Solution().rob(nums) << " 14" << endl;
    return 0;
}
