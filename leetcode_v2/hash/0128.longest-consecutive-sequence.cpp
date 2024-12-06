#include "header.h"

bool comp (int& a, int& b) {
    return a < b;
}

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }

        std::sort(nums.begin(), nums.end(), comp); // 这一句时间复杂度超了
        unordered_map<int, int> mappings;
        for (const auto& num : nums) {
            mappings[num] = 1;
        }

        for (const auto& num : nums) {
            auto iter = mappings.find(num);
            if (iter == mappings.end()) {
                continue;
            }
            auto pre = mappings.find(num-1);
            if (iter->second > 0 && pre != mappings.end()) {
                iter->second = pre->second + 1;
            }
        }

        int result = 0;
        for (auto iter = mappings.begin(); iter != mappings.end(); iter++) {
            result = max(result, iter->second);
        }
        return result;
    }
};

int main(int argc, char* argv[]) {
    vector<int> nums = {10, 4, 20, 1, 3, 2};
    cout << Solution().longestConsecutive(nums) << endl;
    nums = {0,3,7,2,5,8,4,6,0,1};
    cout << Solution().longestConsecutive(nums) << endl;
    nums = {4, 0, -4, -2, 2, 5, 2, 0, -8, -8, -8, -8, -1, 7, 4, 5, 5, -4, 6, 6, -3};
    cout << Solution().longestConsecutive(nums) << endl;

    return 0;
}
