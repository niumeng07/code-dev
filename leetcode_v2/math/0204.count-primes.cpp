/* 给定整数 n ，返回 所有小于非负整数 n 的质数的数量 。
 *
 *
 *
 * 示例 1：
 *
 * 输入：n = 10
 * 输出：4
 * 解释：小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。
 * 示例 2：
 *
 * 输入：n = 0
 * 输出：0
 * 示例 3：
 *
 * 输入：n = 1
 * 输出：0
 *
 *
 * 提示：
 *
 * 0 <= n <= 5 * 106
 * */
#include "header.h"

class Solution {
public:
    int countPrimes(int n) {
        // 怎样判断一个数是质数，除了1和它自身，没有其它约数
    }
};

int main(int argc, char *argv[]) {
    cout << Solution().countPrimes(10) << endl;
    cout << Solution().countPrimes(0) << endl;
    cout << Solution().countPrimes(1) << endl;
    return 0;
}
