#include "header.h"

/*
 * 索引从0开始长度为N的数组A，包含0到N - 1的所有整数。找到最大的集合S并返回其大小，其中 S[i] = {A[i], A[A[i]], A[A[A[i]]], ... }且遵守以下的规则。
 *
 * 假设选择索引为i的元素A[i]为S的第一个元素，S的下一个元素应该是A[A[i]]，之后是A[A[A[i]]]...
 * 以此类推，不断添加直到S出现重复的元素。
 *
 * 示例 1:
 * 输入: A = [5,4,0,3,1,6,2]
 * 输出: 4
 *
 * 解释:
 * A[0] = 5, A[1] = 4, A[2] = 0, A[3] = 3, A[4] = 1, A[5] = 6, A[6] = 2.
 *
 * 其中一种最长的 S[K]:
 * S[0] = {A[0], A[5], A[6], A[2]} = {5, 6, 2, 0}
 * */

class Solution {
public:
    int nums_size = 0;
    int steps = 0;

    int arrayNestingImpl(vector<int>& nums, vector<int>& dp, vector<bool>& visited, int i) {
        if (i >= nums_size || nums[i] >= nums_size || visited[i]) {
            return dp[i];
        }

        visited[i] = true;

        if (dp[nums[i]] > 0) {
            dp[i] = 1 + dp[nums[i]];
        } else {
            dp[i] = 1 + arrayNestingImpl(nums, dp, visited, nums[i]);  // 如果该元素访问过
        }

        return dp[i];
    }

    int arrayNesting(vector<int>& nums) {
        nums_size = nums.size();

        if (nums_size <= 0) return 0;
        vector<int> dp(nums_size, 0);
        vector<bool> visited(nums_size, false);

        for (int i = 0; i < nums_size; i++) {
            if (dp[i] == 0) {
                arrayNestingImpl(nums, dp, visited, i);
            }
        }

        // print_vector(dp);

        int result = 0;
        for (int i = 0; i < dp.size(); i++) {
            result = max(result, dp[i]);
        }
        return result;
    }
};

int main(int argc, char* argv[]) {
    vector<int> nums = {5, 4, 0, 3, 1, 6, 2};
    cout << Solution().arrayNesting(nums) << " ==? 4" << endl;

    nums = {0, 1, 2};
    cout << Solution().arrayNesting(nums) << " ==? 1" << endl;

    nums = {0, 2, 1};
    cout << Solution().arrayNesting(nums) << " ==? 2" << endl;
    return 0;
}
