#include "header.h"


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;

        unordered_map<int, int> need;
        for (int i = 0; i < nums.size(); i++) {
            need.insert(std::make_pair(target - nums[i], i));
        }
        // 当前int所需要的对应int

        for (int i = 0; i < nums.size(); i++) {
            const auto& iter = need.find(nums[i]);
            if (iter != need.end() && i != need[nums[i]]) {
                result.push_back(i);
                result.push_back(need[nums[i]]);
                return result;
            }
        }

        return result;
    }
};

int main(int argc, char *argv[]) {
    vector<int> input = {3, 2, 4};
    print_vector(Solution().twoSum(input, 6));
    return 0;
    input = {2, 7, 11, 15};
    print_vector(Solution().twoSum(input, 9));
    return 0;
}
