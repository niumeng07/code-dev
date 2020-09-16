#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class FirstMissingPositive {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        for (auto iter = nums.begin(); iter != nums.end();) {
            if (*iter <= 0)
                nums.erase(iter);
            else
                break;
        }
        if (nums.empty()) return 1;
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] != i + 1) return i + 1;
        return nums.size() + 1;
    }
    int firstMissingPositive2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if (nums.empty()) return 1;
        int result = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= 0 || nums[i] < result) continue;
            if (nums[i] == result) {
                result++;
                continue;
            } else
                return result;
        }
        return result;
    }
};
