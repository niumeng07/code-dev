#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <numeric>

using namespace std;

class Solution {
public:
    string status2str(vector<vector<int> >& status,int target) {
        string res = "";
        for (const auto& v : status) {
            for (const auto& i : v) {
                res += (std::to_string(i) + ", ");
            }
            res += "|";
        }
        res += std::to_string(target);
        return res;
    }

    vector<vector<int> > searched;  // 已经搜索过的空间
    bool setNums(vector<vector<int> >& status, vector<int>& nums, int k,
                 int target) {
        // 1. 如果nums为空,判断status是否满足每个item_vec的和都是target
        // 2.
        // 如果nums不为空,从nums中取出一个元素,如次放入到status的每个item_vec中,递归
        if (nums.empty()) {
            for (int i = 0; i < status.size(); i++) {
                if (std::accumulate(status[i].begin(), status[i].end(), 0) !=
                    target) {
                    cout << "nums.empty false " << status2str(status, target)  << std::endl;
                    return false;
                }
            }
            cout << "nums.empty true "  << status2str(status, target) << std::endl;
            return true;
        } else {
            int curr = nums.back();
            nums.pop_back();
            for (int i = 0; i < status.size(); i++) {
                int curr_sum = std::accumulate(
                        status[i].begin(), status[i].end(), 0);
                if (curr_sum + curr > target) {
                    continue;
                }
                // 这里要做去重检测,怎样判断一个队列是否遇到过
                status[i].push_back(curr);
                if (setNums(status, nums, k, target)) {
                    return true;
                }
                status[i].pop_back();
            }
            nums.push_back(curr);
            return false;
        }
    }
    bool setNums2(vector<int>& status, vector<int>& nums, int k, int target) {
        return true;
    }

    // 1 <= k <= len(nums) <= 16,最大16个数
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        if (k == 1) return true;
        int sums = accumulate(nums.begin(), nums.end(), 0);

        if (sums % k > 0) return false;  // 不能整除,一定不可分
        int target = sums / k;
        // 选取子集,每个子集的和为target
        // 如果用动态规划解，怎样定义状态

        vector<vector<int> > status(k, vector<int>());
        // 方法1,循环解
        std::sort(nums.begin(), nums.end());
        return setNums(status, nums, k, target); // 这个方法的耗时不过关

        vector<int> status2(k, 0);
        // 方法2,DP,status的每个元素表示当前队列中选择了哪些idx的数(最多一共16个数)
        setNums2(status2, nums, k, target);
    }
};
