#include "header.h"

class Solution {
public:
    // 有没有异常情况
    // 空数组
    // 数组长度为1或才2
    // 没有正确答案
    vector<int> twoSum(vector<int>& numbers, int target) {
        // 数组为升序
        int i = 0;
        int j = numbers.size() - 1;

        vector<int> results;

        while (i < j) {
            int curr_sum = numbers[i] + numbers[j];
            if (curr_sum == target) {
                results.push_back(i + 1);
                results.push_back(j + 1);
                return results;
            } else if (curr_sum > target) {
                j--;
            } else if (curr_sum < target) {
                i++;
            }
        }
        return results;
    }
};
