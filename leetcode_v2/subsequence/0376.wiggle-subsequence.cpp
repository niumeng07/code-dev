#include "header.h"

/* 376. 摆动序列  最长摆动子序列
 * 中等
 * 相关标签
 * 相关企业
 * 如果连续数字之间的差严格地在正数和负数之间交替，则数字序列称为 摆动序列
 * 。第一个差（如果存在的话）可能是正数或负数。仅有一个元素或者含两个不等元素的序列也视作摆动序列。
 *
 * 例如， [1, 7, 4, 9, 2, 5] 是一个 摆动序列 ，因为差值 (6, -3, 5, -7, 3) 是正负交替出现的。
 *
 * 相反，[1, 4, 7, 2, 5] 和 [1, 7, 4, 5, 5]
 * 不是摆动序列，第一个序列是因为它的前两个差值都是正数，第二个序列是因为它的最后一个差值为零。 子序列
 * 可以通过从原始序列中删除一些（也可以不删除）元素来获得，剩下的元素保持其原始顺序。
 *
 * 给你一个整数数组 nums ，返回 nums 中作为 摆动序列 的 最长子序列的长度 。
 *
 * 示例 1：
 *
 * 输入：nums = [1,7,4,9,2,5]
 * 输出：6
 * 解释：整个序列均为摆动序列，各元素之间的差值为 (6, -3, 5, -7, 3) 。
 * 示例 2：
 *
 * 输入：nums = [1,17,5,10,13,15,10,5,16,8]
 * 输出：7
 * 解释：这个序列包含几个长度为 7 摆动序列。
 * 其中一个是 [1, 17, 10, 13, 10, 16, 8] ，各元素之间的差值为 (16, -7, 3, -3, 6, -8) 。
 * 示例 3：
 *
 * 输入：nums = [1,2,3,4,5,6,7,8,9]
 * 输出：2
 * */

// 动态规划问题
// 当前元素选和不选两种情况

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int size = nums.size();
        if (size <= 1) {
            return size;
        }

        // 初始化为1，单子元素认为是摆动序列
        vector<int> dp(size, 1);

        // 最长子序列列时，当前元素和前一个元素差值之间的符号1为正,-1为负,0为初始化或首元素
        vector<int> label(size, 0);

        for (int i = 1; i < size; i++) {
            for (int j = 0; j < i; j++) {
                if ((j == 0 && nums[i] != nums[j]) || label[j] * (nums[i] - nums[j]) < 0) {
                    // 只有当符合条件 {j和前一个元素差值的符号与ij素材差值的符号不同} 时才认为可以从dp[j]转移过来
                    // j==0为第一个元素,只要两个值不相等即可
                    dp[i] = max(dp[i], dp[j] + 1);
                    label[i] = (nums[i] - nums[j] > 0) ? 1 : -1;
                }
            }
        }
        return dp[dp.size() - 1];
    }
};

int main(int argc, char* argv[]) {
    vector<int> nums = {1, 7, 4, 9, 2, 5};
    // cout << Solution().wiggleMaxLength(nums) << endl;
    nums = {0, 0};
    cout << Solution().wiggleMaxLength(nums) << endl;
    nums = {0, 0, 1, 1};
    cout << Solution().wiggleMaxLength(nums) << endl;
    return 0;
}
