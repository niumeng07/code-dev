#include "header.h"
/*
 * 给定一个包含红色、白色和蓝色、共 n 个元素的数组 nums ，原地
 * 对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。 我们使用整数 0、 1 和 2
 * 分别表示红色、白色和蓝色。 必须在不使用库内置的 sort 函数的情况下解决这个问题。
 *
 * 示例 1：
 * 输入：nums = [2,0,2,1,1,0]
 * 输出：[0,0,1,1,2,2]
 *
 * 示例 2：
 * 输入：nums = [2,0,1]
 * 输出：[0,1,2]
 * */

// class Solution {
// public:
    void sortColors(vector<int>& nums) {
        // 双指针，先遍历第一遍把0换到最左边
        int i = 0;
        int j = nums.size() - 1;
        while (i < j) {
            if (nums[i] > 0 && nums[j] == 0) {
                std::swap(nums[i], nums[j]);
                i++;
                j--;
            } else if (nums[i] == 0) {
                i++;
            } else if (nums[j] > 0) {
                j--;
            } else {
                // 这里不应该有
            }
        }
        for (i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                break;
            }
        }
        // 到这里i的位置是第一个非0的元素
        j = nums.size() - 1;
        while (i < j) {
            if (nums[i] > 1 && nums[j] == 1) {
                std::swap(nums[i], nums[j]);
                i++;
                j--;
            } else if (nums[i] == 1) {
                i++;
            } else if (nums[j] > 1) {
                j--;
            } else {
                // 这里不应该有
            }
        }
    }
// };

int main(int argc, char* argv[]) {
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    sortColors(nums);
    cout << endl;
    return 0;
}
