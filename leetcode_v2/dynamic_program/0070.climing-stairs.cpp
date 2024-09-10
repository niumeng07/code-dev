/*
 * 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
 * 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
 *
 * 示例 1：
 * 输入：n = 2
 * 输出：2
 * 解释：有两种方法可以爬到楼顶。
 * 1. 1 阶 + 1 阶
 * 2. 2 阶
 *
 * 示例 2：
 * 输入：n = 3
 * 输出：3
 * 解释：有三种方法可以爬到楼顶。
 * 1. 1 阶 + 1 阶 + 1 阶
 * 2. 1 阶 + 2 阶
 * 3. 2 阶 + 1 阶
 * */

#include "header.h"

class Solution {
public:
    // 0->0
    // 1->1
    // 2=dp[0]+dp1[1]
    // 3=dp[1]+dp[2]
    // 4=dp[2]+dp[3]
    int climbStairs(int n) {
        return climbStairsV2(n);
        vector<int> dp = {1, 1};

        for (int i = 2; i <= n; i++) {
            dp.push_back(dp[i - 2] + dp[i - 1]);
        }
        return dp[n];
    }

    int climbStairsV2(int n) {  // 比climbStairs 减少内在
        int dp1 = 1;
        int dp2 = 1;
        int tmp = 0;
        for (int i = 2; i <= n; i++) {
            tmp = dp2;
            dp2 = dp2 + dp1;
            dp1 = tmp;
        }
        return dp2;
    }
};

int main(int argc, char *argv[]) {
    cout << Solution().climbStairs(2) << " == 2" << endl;
    cout << Solution().climbStairs(3) << " == 3" << endl;
    return 0;
}
