/*
 * 给你一个仅由整数组成的有序数组，其中每个元素都会出现两次，唯有一个数只会出现一次。
 * 请你找出并返回只出现一次的那个数。
 * 你设计的解决方案必须满足 O(log n) 时间复杂度和 O(1) 空间复杂度。
 *
 * 示例 1:
 * 输入: nums = [1,1,2,3,3,4,4,8,8]
 * 输出: 2
 *
 * 示例 2:
 * 输入: nums =  [3,3,7,7,10,11,11]
 * 输出: 10
 * */

#include "header.h"

class Solution {
public:
    bool checkIth(vector<int>& nums, int i) {
        if (i == 0 && nums[i] != nums[i + 1]) {
            return true;
        } else if (i == nums.size() - 1 && nums[i] != nums[i - 1]) {
            return true;
        } else if (i > 0 && i < nums.size() - 1 && nums[i] != nums[i - 1] && nums[i] != nums[i + 1]) {
            return true;
        }
        return false;
    }

    int singleNonDuplicateImpl(vector<int>& nums, int i, int j) {
        if (checkIth(nums, i)) {
            return nums[i];
        } else if (checkIth(nums, j)) {
            return nums[j];
        }

        int m = (i + j) / 2;

        if (nums[m] != nums[m - 1] && nums[m] != nums[m + 1]) {
            return nums[m];  // 中间这个元素是结果
        } else if (nums[m] == nums[m - 1]) {
            if (m % 2 == 0) {
                return singleNonDuplicateImpl(nums, i + 1, m - 1);
            } else {
                return singleNonDuplicateImpl(nums, m + 1, j - 1);
            }
        } else {
            if (m % 2 == 0) {
                return singleNonDuplicateImpl(nums, m + 1, j - 1);
            } else {
                return singleNonDuplicateImpl(nums, i + 1, m - 1);
            }
        }
    }

    int singleNonDuplicate(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }

        // 二分解析 O(Log(N))
        return singleNonDuplicateImpl(nums, 0, nums.size() - 1);
    }
};


int main(int argc, char* argv[]) {
    vector<int> nums = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    cout << Solution().singleNonDuplicate(nums) << endl;
    nums = {3, 3, 7, 7, 10, 11, 11};
    cout << Solution().singleNonDuplicate(nums) << endl;
    nums = {1, 1, 2};
    cout << Solution().singleNonDuplicate(nums) << endl;
    nums = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    cout << Solution().singleNonDuplicate(nums) << endl;
    nums = {1};
    cout << Solution().singleNonDuplicate(nums) << endl;
    nums = {7, 7, 10, 11, 11, 12, 12};
    cout << Solution().singleNonDuplicate(nums) << endl;
}

// 1 & 1 = 1
// 1 | 1 = 1
// 1 ~ 1 = 0
