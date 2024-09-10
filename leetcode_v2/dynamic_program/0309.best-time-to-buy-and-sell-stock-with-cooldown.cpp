/* 给定一个整数数组prices，其中第  prices[i] 表示第 i 天的股票价格 。​
 *
 * 设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:
 *
 * 卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。
 * 注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
 *
 *
 * 示例 1:
 * 输入: prices = [1,2,3,0,2]
 * 输出: 3
 * 解释: 对应的交易状态为: [买入, 卖出, 冷冻期, 买入, 卖出]
 *
 * 示例 2:
 * 输入: prices = [1]
 * 输出: 0
 *
 * 提示：
 * 1 <= prices.length <= 5000
 * 0 <= prices[i] <= 1000
 * */

#include "header.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int m = prices.size();
        if (m <= 1) {
            return 0;
        }

        // 求累计最大收益, 以下vector保存的是收益变化，买入动作代表支出，卖出代表收益(当天结束后的收益)
        vector<int> h(m, 0);   // 第i天持有该股票时最大收益
        vector<int> e(m, 0);   // 第i天不持有该股票且不在冷冻期时最大收益
        vector<int> ec(m, 0);  // 第i天不持有该股票且在冷冻期时最大收益

        h[0] = -prices[0];  // 买入为负收益

        for (int i = 1; i < m; i++) {
            // 持有该股票: 有可能是在i天买入的，也有可能是此前就有的(i-1及之前买入)
            // 如果是在当天买入的: 说明i-1天未持有,i-1天未卖出(即i-1时不在冷期),收益累计是
            // e[i-1] - prices[i] 如果是在此前持有的: 收益累计仍是 h[i-1]
            h[i] = max(h[i - 1], e[i - 1] - prices[i]);

            // 当天未持有且不在冷冻期,->第i-1天有可能是冷冻期，有可能不是
            // 如果i-1天是冷冻期: 收益是 ec[i-1]
            // 如果i-1天不是冷冻期: 收益是 e[i-1]
            e[i] = max(e[i - 1], ec[i - 1]);

            // 当时是冷冻期,卖出了,如果i-1天持有这支股票了
            ec[i] = h[i - 1] + prices[i];
        }

        return max(h[m-1], max(e[m-1], ec[m-1]));
    }
};

int main(int argc, char* argv[]) {
    vector<int> prices = {1, 2, 3, 0, 2};
    cout << Solution().maxProfit(prices) << endl;

    prices = {1};
    cout << Solution().maxProfit(prices) << endl;
    return 0;
}
