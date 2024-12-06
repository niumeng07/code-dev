/*给你一个 只包含正整数 的 非空 数组 nums 。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
 *
 * 示例 1：
 * 输入：nums = [1,5,11,5]
 * 输出：true
 * 解释：数组可以分割成 [1, 5, 5] 和 [11] 。
 *
 * 示例 2：
 * 输入：nums = [1,2,3,5]
 * 输出：false
 * 解释：数组不能分割成两个元素和相等的子集。
 * */

#include "header.h"

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sums = accumulate(nums.begin(), nums.end(), 0);
        if (sums % 2 > 0) {
            return false;
        }

        int space = sums / 2;  // 背包总体积
        vector<vector<int>> matrix(space, vector<int>(nums.size(), 0));   // 元素个数最多为nums.size()个
    }
};

int main(int argc, char* argv[]) {
    vector<int> nums = {1, 5, 11, 5};
    cout << Solution().canPartition(nums) << " ==? 1" << endl;
    nums = {1, 2, 3, 5};
    cout << Solution().canPartition(nums) << " ==? 0" << endl;
    return 0;
}
