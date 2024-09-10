/* 给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。
 *
 * 子序列 是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。例如，[3,6,2,7] 是数组
 * [0,3,1,6,2,2,7] 的 子序列 。
 *
 * 示例 1：
 * 输入：nums = [10,9,2,5,3,7,101,18]
 * 输出：4
 * 解释：最长递增子序列是 [2,3,7,101]，因此长度为 4 。
 *
 * 示例 2：
 * 输入：nums = [0,1,0,3,2,3]
 * 输出：4
 *
 * 示例 3：
 * 输入：nums = [7,7,7,7,7,7,7]
 * 输出：1
 *
 * 提示：
 * 1 <= nums.length <= 2500
 * -104 <= nums[i] <= 104
 *
 * 进阶：
 * 你能将算法的时间复杂度降低到 O(n log(n)) 吗?
 * */

// 问题分析
// 10, 9, 2, 5, 3, 7, 101, 18
// 1
//     如果9<10否则
//        如果2>9 否则
//           如果5>2
// 看上去1维不够用
#include "header.h"

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int m = nums.size();
        if (m == 0) {
            return 0;
        }

        vector<int> vec(m, 1);  // 从第0位开始，到第i位的最长序列
        // vec[0] = 1;   // 省略: 从第0到到第0位，长度为1
        int max_len = 1;
        for (int i = 1; i < m; i++) { // 时间复杂度分析：这一层遍历是O(N)
            // i=1，即前两位(0~1)
            // 如果nums[i]>nums[i-1]
            for (int j = 0; j < i; j++) { // 这一层遍历是O(log(N))
                if (nums[i] > nums[j]) {
                    vec[i] = max(vec[i], vec[j] + 1);
                }
            }
            max_len = max(max_len, vec[i]);
        }

        return max_len;
    }
};

int main(int argc, char* argv[]) {
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << Solution().lengthOfLIS(nums) << " 标准答案：4" << endl;

    nums = {0, 1, 0, 3, 2, 3};
    cout << Solution().lengthOfLIS(nums) << " 标准答案：4" << endl;

    nums = {7, 7, 7, 7, 7, 7, 7};
    cout << Solution().lengthOfLIS(nums) << " 标准答案：1" << endl;

    nums = {4, 10, 4, 3, 8, 9};
    cout << Solution().lengthOfLIS(nums) << " 标准答案：3" << endl;

    nums = {1, 3, 6, 7, 9, 4, 10, 5, 6};
    cout << Solution().lengthOfLIS(nums) << " 标准答案：6" << endl;

    nums = {0};
    cout << Solution().lengthOfLIS(nums) << " 标准答案：1" << endl;

    return 0;
}
