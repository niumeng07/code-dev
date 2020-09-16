/**
 * @file bitwise_a_n_d_num_range.h
 *
 * @author myliuda@sina.com
 * @version 0.0.1
 * @date 2020-02-07
 *
 * @brief
 * Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND
 * of all numbers in this range, inclusive.
 *
 * Example 1:
 *
 * Input: [5,7]
 * Output: 4
 * Example 2:
 *
 * Input: [0,1]
 * Output: 0
 *
 * 这个题目明显遍历不是最佳解决方案，
 * 要想位操作背后的实现
 *
 * 所有数中，只要有任一个数在某一（二进制）位为0，则结果在该位为0
 * 若存在偶数，则第0位为0
 * 若/2后的结果存在偶数，则第1位为0
 * 继续/2，直到所有结果为0
 * 8 7
 * 1000 0111
 * 有偶数，第0位为0
 * 4 3
 * 有偶数，第1位为0
 * 2 1
 * 有偶数， 第2位为0
 * 1 0
 * 有偶数，第4位为0
 *
 * 结果0000
 *
 */
#include <iostream>

class BitwiseANDNumRange {
public:
    bool isEven(int x) {
        if (x % 2 == 0)
            return true;
        else
            return false;
    }
    int rangeBitwiseAndTimeExc(int m, int n) {
        int bitwiseand = 2147483647;
        for (int i = m; i <= n; i++) {
            bitwiseand = bitwiseand & i;
        }
        return bitwiseand;
    }
    int rangeBitwiseAndTime(int m, int n) {
        if (n > m) return 0;
        if (n == m) return m;
        int result = 0;
        int index = 0;
        for (int i = m; i <= n; i++) {
            if (m == 0 && n == 0) break;
            if (isEven(i)) {
                result = result | (1 << index);
                index++;
                continue;
            }
        }
        return 0;
    }
};

/*
1001001
1001010
1001011
1001100
1001101
全部为1的位
1001000
*/
/*
 * 101
 * 110
 * 111
 * */
