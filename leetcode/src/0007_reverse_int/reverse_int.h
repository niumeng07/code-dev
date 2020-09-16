#include <limits>
/**
 * @brief
 * Reverse digits of an integer.
 *
 * Example1: x = 123, return 321
 * Example2: x = -123, return -321
 *
 * click to show spoilers.
 *
 * Note:
 * The input is assumed to be a 32-bit signed integer. Your function should
 * return 0 when the reversed integer overflows.
 *
 */
using namespace std;
class ReverseInt {
public:
    int reverse(int input) {
        long result = 0;
        while (input != 0) {
            result = result * 10 + input % 10;
            if (result > numeric_limits<int>::max() ||
                result < numeric_limits<int>::min())
                return 0;
            input = input / 10;
        }
        return result;
    }
};
