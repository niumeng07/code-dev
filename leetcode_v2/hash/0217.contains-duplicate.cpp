#include "header.h"

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::unordered_map<int, int> nums_count;

        for (const auto& num : nums) {
            std::unordered_map<int, int>::iterator iter = nums_count.find(num);
            if (iter != nums_count.end()) {
                (iter->second)++;
            } else {
                nums_count[num] = 1;
            }
        }

        for (const auto& iter : nums_count) {
            if (iter.second > 1) {
                return true;
            }
        }

        return false;
    }
};

int main(int argc, char* argv[]) {
    vector<int> nums = {1, 2, 3, 1};
    cout << Solution().containsDuplicate(nums) << " == 1" << endl;
    nums = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
    cout << Solution().containsDuplicate(nums) << " == 1" << endl;
    nums = {1, 2, 3, 4};
    cout << Solution().containsDuplicate(nums) << " == 0" << endl;
    return 0;
}
