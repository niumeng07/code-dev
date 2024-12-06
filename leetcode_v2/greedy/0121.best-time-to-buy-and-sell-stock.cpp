#include "header.h"

/*
 * 121. 买卖股票的最佳时机
 * 简单
 * 相关标签
 * 相关企业
 * 给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。
 *
 * 你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票。设计一个算法来计算你所能获取的最大利润。
 *
 * 返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。
 *
 * 示例 1：
 * 输入：[7,1,5,3,6,4]
 * 输出：5
 * 解释：在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
 *      注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格；同时，你不能在买入前卖出股票。
 *
 * 示例 2：
 * 输入：prices = [7,6,4,3,1]
 * 输出：0
 * 解释：在这种情况下, 没有交易完成, 所以最大利润为 0。
 * */

// 该题仅能买卖一次？
// 如果prices[i+1] < prices[i]  i位置一定不是适合买入的时机
// 依次更新i

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        if (size <= 1) {
            return 0;
        }

        int result = 0;
        // 这个方法应该还能继续优化，把每个位置之后最大的值记下来，可以复用
        for (size_t i = 0; i < size; i++) {
            if (i < size - 1 && prices[i + 1] <= prices[i]) {
                continue;
            }
            for (size_t j = i + 1; j < size; j++) {
                if (prices[j] <= prices[i]) {
                    i = j;
                    continue;
                }

                int curr_profit = prices[j] - prices[i];
                result = max(result, curr_profit);
            }
        }
        return result;
    }
};



int main(int argc, char *argv[])
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    // cout << Solution().maxProfit(prices) << endl;
    prices = {1, 2, 4, 2, 5, 7, 2, 4, 9, 0, 9};
    cout << Solution().maxProfit(prices) << endl;
    return 0;
}
