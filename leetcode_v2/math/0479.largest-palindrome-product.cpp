#include "header.h"

class Solution {
public:
    int largestPalindrome(int n) {
        // 首选求大n位数的最大数
        int max_n = pow(10, n) - 1;
        int max_num = max_n * max_n; // 由两个n位数相乘可以得到的最大数
        // 求其左x位，右y位

        return 0;
    }
};

int main(int argc, char *argv[])
{
    cout << Solution().largestPalindrome(2) << " === 987?" << endl;
    return 0;
}
