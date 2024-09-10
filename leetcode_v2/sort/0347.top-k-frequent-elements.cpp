#include "header.h"
/*
 * 给你一个整数数组 nums 和一个整数 k ，请你返回其中出现频率前 k 高的元素。你可以按 任意顺序 返回答案。
 * 示例 1:
 * 输入: nums = [1,1,1,2,2,3], k = 2
 * 输出: [1,2]
 *
 * 示例 2:
 * 输入: nums = [1], k = 1
 * 输出: [1]
 * */

// Solution 省掉了
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> results;
        unordered_map<int, int> freqs;
        // 对每个元素计数
        for (const auto& num : nums) {
            if (freqs.find(num) == freqs.end()) {
                freqs[num] = 1;
            } else {
                freqs[num] = freqs[num] + 1;
            }
        }
        for (const auto& item : freqs) {
            auto iter = results.begin();
            for (; iter < results.end();) {
                if (item.second < freqs[*iter]) {
                    iter++;
                } else {
                    break;
                }
            }
            if (iter != results.end() || results.size() < k) {
                results.insert(iter, item.first);
            }
            if (results.size() > k) {  // 需要把最后一个元素erase掉
                results.erase(results.end() - 1);
            }
        }

        return results;
    }

int main(int argc, char *argv[])
{
    vector<int> nums = {1,1,1,2,2,3};
    topKFrequent(nums, 2);
    return 0;
}
