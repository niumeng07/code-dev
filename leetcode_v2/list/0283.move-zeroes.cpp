#include "header.h"

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int m = nums.size();
        if (m <= 1) {
            return;
        }
        int i = 0;
        int j;
        while (i < m) {
            while (i < m && nums[i] != 0) i++;
            if (i >= m - 1) break;  // -1是因为j从i+1开始,提前判断了
            j = i + 1;
            while (j < m && nums[j] == 0) j++;
            if (j >= m) break;
            // nums[i] = nums[i] + nums[j];
            // nums[j] = nums[i] - nums[j];
            // nums[i] = nums[i] - nums[j];

            // swap(nums[i], nums[j]);
            nums[i] = nums[j];
            nums[j] = 0;
            i++;
        }
    }
};

int main(int argc, char* argv[]) {
    vector<int> nums = {0, 1, 0, 3, 12};
    // Solution().moveZeroes(nums);
    // print_vector(nums);

    // nums = {0};
    // Solution().moveZeroes(nums);
    // print_vector(nums);

    // nums = {0, 0, 0, 0};
    // Solution().moveZeroes(nums);
    // print_vector(nums);

    // nums = {1, 1, 1, 1};
    // Solution().moveZeroes(nums);
    // print_vector(nums);

    // nums = {1, 1, 1, 1, 0, 0};
    // Solution().moveZeroes(nums);
    // print_vector(nums);

    nums = {4, 2, 4, 0, 0, 3, 0, 5, 1, 0};
    Solution().moveZeroes(nums);
    print_vector(nums);
    return 0;
}
