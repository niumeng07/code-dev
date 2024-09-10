/* 给你一个由 不同 整数组成的数组 nums ，和一个目标整数 target 。请你从 nums 中找出并返回总和为 target
 * 的元素组合的个数。 题目数据保证答案符合 32 位整数范围。
 *
 * 示例 1：
 * 输入：nums = [1,2,3], target = 4
 * 输出：7
 * 解释：
 * 所有可能的组合为：
 * (1, 1, 1, 1)
 * (1, 1, 2)
 * (1, 2, 1)
 * (1, 3)
 * (2, 1, 1)
 * (2, 2)
 * (3, 1)
 * 请注意，顺序不同的序列被视作不同的组合。
 *
 * 示例 2：
 * 输入：nums = [9], target = 3
 * 输出：0
 * */

#include "header.h"

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<uint64_t> vec(target + 1, 0);
        vec[0] = 1;
        // 1 1 2 2 0
        // 1 1 2 3 4
        for (int i = 1; i < vec.size(); i++) {
            // 计算当target=1时的组法
            for (const auto& num : nums) {
                if (i - num >= 0) {
                    vec[i] += vec[i - num];
                }
            }
        }

        return vec[vec.size() - 1];
    }
};

int main(int argc, char* argv[]) {
    vector<int> nums = {1, 2, 3};
    cout << Solution().combinationSum4(nums, 4) << ", 7" << endl;

    nums = {9};
    cout << Solution().combinationSum4(nums, 3) << ", 0" << endl;

    nums = {10,  20,  30,  40,  50,  60,  70,  80,  90,  100, 110, 120, 130, 140, 150, 160, 170, 180, 190, 200,
            210, 220, 230, 240, 250, 260, 270, 280, 290, 300, 310, 320, 330, 340, 350, 360, 370, 380, 390, 400,
            410, 420, 430, 440, 450, 460, 470, 480, 490, 500, 510, 520, 530, 540, 550, 560, 570, 580, 590, 600,
            610, 620, 630, 640, 650, 660, 670, 680, 690, 700, 710, 720, 730, 740, 750, 760, 770, 780, 790, 800,
            810, 820, 830, 840, 850, 860, 870, 880, 890, 900, 910, 920, 930, 940, 950, 960, 970, 980, 990, 111};
    cout << Solution().combinationSum4(nums, 999) << ", 1" << endl;
    return 0;
}
