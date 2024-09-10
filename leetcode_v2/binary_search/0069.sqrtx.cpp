/* 给你一个非负整数 x ，计算并返回 x 的 算术平方根 。
 * 由于返回类型是整数，结果只保留 整数部分 ，小数部分将被 舍去 。
 * 注意：不允许使用任何内置指数函数和算符，例如 pow(x, 0.5) 或者 x ** 0.5 。
 *
 * 示例 1：
 * 输入：x = 4
 * 输出：2
 *
 * 示例 2：
 * 输入：x = 8
 * 输出：2
 * 解释：8 的算术平方根是 2.82842..., 由于返回类型是整数，小数部分将被舍去。
 * */

#include "header.h"

// class Solution {
// public:
    int mySqrt(int x) {
        if (x==1) return 1;
        if (x>= 2147395600) return 46340;

        int start = 0;
        int end = 46340;
        int k = (start+end) / 2;

        while (!(k * k <= x && (k + 1) * (k + 1) > x)) {
            if (k * k < x) {
                start = k + 1;
            } else if (k * k > x) {
                end = k - 1;
            }
            k = (start + end) / 2;
        }
        return k;
    }
// };

int main(int argc, char *argv[]) {
    cout << mySqrt(2147395600) << endl;
    cout << mySqrt(8) << endl;
    cout << mySqrt(4) << endl;
    cout << mySqrt(1) << endl;
    cout << mySqrt(10) << endl;
    cout << mySqrt(11) << endl;
    cout << mySqrt(12) << endl;
    cout << mySqrt(13) << endl;
    cout << mySqrt(14) << endl;
    cout << mySqrt(15) << endl;
    cout << mySqrt(16) << endl;
    return 0;
}
