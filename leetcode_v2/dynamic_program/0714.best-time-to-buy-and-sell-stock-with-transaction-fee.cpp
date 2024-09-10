/* 给定一个整数数组 prices，其中 prices[i]表示第 i 天的股票价格 ；整数 fee 代表了交易股票的手续费用。
 * 你可以无限次地完成交易，但是你每笔交易都需要付手续费。如果你已经购买了一个股票，在卖出它之前你就不能再继续购买股票了。
 *
 * 返回获得利润的最大值。
 *
 * 注意：这里的一笔交易指买入持有并卖出股票的整个过程，每笔交易你只需要为支付一次手续费。
 *
 * 示例 1：
 * 输入：prices = [1, 3, 2, 8, 4, 9], fee = 2
 * 输出：8
 * 解释：能够达到的最大利润:
 * 在此处买入 prices[0] = 1
 * 在此处卖出 prices[3] = 8
 * 在此处买入 prices[4] = 4
 * 在此处卖出 prices[5] = 9
 * 总利润: ((8 - 1) - 2) + ((9 - 4) - 2) = 8
 *
 * 示例 2：
 * 输入：prices = [1,3,7,5,10,3], fee = 3
 * 输出：6
 *
 * 提示：
 * 1 <= prices.length <= 5 * 104
 * 1 <= prices[i] < 5 * 104
 * 0 <= fee < 5 * 104
 * */

#include "header.h"

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int m = prices.size();
        if (m <= 1) return 0;

        // 第i天
        // I. 有卖出操作   收益=收益'+prices[i]-fee
        // II. 有买入操作  收益=收益'-prices[i]
        // III. 仅持有、未操作  收益=收益'
        // IV. 未持有、未操作   收益=收益'
        // III和IV能否合并，?收益=收益'

        vector<int> b(m, 0);
        vector<int> s(m, 0); // 第0天不可能卖出
        vector<int> h(m, 0); // 第0天不可能已经持有
        vector<int> e(m, 0); // 第0天空仓为0
        b[0] = -prices[0];  // 第0天买入
        h[0] = -prices[0];  // 如果第0天持有(虚拟)

        for (int i = 1; i < m; i++) {
            s[i] = max(h[i - 1], b[i - 1]) + prices[i] - fee;  // i天卖出，则i-1天要么持有，要行买入
            b[i] = max(s[i - 1], e[i - 1]) - prices[i];  // i天买入,则i-1天要么卖出,要么空仓(iv)_卖入不计算手续费
            h[i] = max(b[i - 1], h[i - 1]);  // i天持有且未操作,则i-1天要么持有，要么买入
            e[i] = max(e[i - 1], s[i - 1]);  // 则i-1天要么空(iv),要么卖出
        }

        return max(max(s[m - 1], b[m - 1]), max(h[m - 1], e[m - 1]));
    }
};

int main(int argc, char* argv[]) {
    vector<int> prices = {1, 3, 2, 8, 4, 9};
    cout << Solution().maxProfit(prices, 2) << endl;

    prices = {1, 3, 7, 5, 10, 3};
    cout << Solution().maxProfit(prices, 3) << endl;

    prices = {1, 3};
    cout << Solution().maxProfit(prices, 1) << endl;
    return 0;
}
