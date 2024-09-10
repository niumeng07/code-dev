#include "header.h"

/*
 * 给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。
 * 请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
 * 你必须设计并实现时间复杂度为 O(n) 的算法解决此问题。
 *
 * 示例 1:
 * 输入: [3,2,1,5,6,4], k = 2
 * 输出: 5
 *
 * 示例 2:
 * 输入: [3,2,3,1,2,4,5,5,6], k = 4
 * 输出: 4
 * */

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if (nums.size() == 0) {
            return 0;
        }
        // 把输入nums调整成一个堆
        make_heap(nums.begin(), nums.end());
        int i = 0;
        int result = nums[0];
        while (i < k) {
            result = nums[0];
            std::pop_heap(nums.begin(), nums.end());  // 注意: pop_heap会把top的元素放到back，需要手动从back删除
            nums.pop_back();
            i++;
        }
        return result;
    }
};

int main(int argc, char* argv[]) {
    Solution solution;

    vector<int> nums = {3, 2, 1, 5, 6, 4};
    cout << solution.findKthLargest(nums, 2) << " " << 5 << endl;

    nums = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    cout << solution.findKthLargest(nums, 4) << " " << 4 << endl;

    return 0;
}
