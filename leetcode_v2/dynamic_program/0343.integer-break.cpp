#include "header.h"

/* 给定一个正整数 n ，将其拆分为 k 个 正整数 的和（ k >= 2 ），并使这些整数的乘积最大化。
 * 返回 你可以获得的最大乘积 。
 *
 *
 * 示例 1:
 * 输入: n = 2
 * 输出: 1
 * 解释: 2 = 1 + 1, 1 × 1 = 1。
 *
 * 示例 2:
 * 输入: n = 10
 * 输出: 36
 * 解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36。
 *
 * 容易分辨这是dp问题
 * 1没办法分     => 初始化为1
 * 2只能分成1和1 => 乘积是1
 * 初始化完成
 * */

class Solution {
public:
    int integerBreak(int n) {
        if (n <= 2) {
            return 1;
        }
        vector<int> vec(n, 1);
        for (int i = 3; i <= n; i++) {
            for (int j = 1; j < i / 2 + 1; j++) {  // j是i分出来的一部分, **j < i/2+2即可**
                // 注意: 2最多分成1+1乘积是1,但如果2做为3的一部分,则最大值是2(下面公式里的的第2个max)
                vec[i - 1] = max(vec[i - 1], max((i - j) * j, vec[i - j - 1] * j));
            }
        }
        return vec[vec.size() - 1];
    }
};

int main(int argc, char *argv[]) {
    cout << Solution().integerBreak(2) << endl;
    cout << Solution().integerBreak(10) << endl;
    return 0;
}
