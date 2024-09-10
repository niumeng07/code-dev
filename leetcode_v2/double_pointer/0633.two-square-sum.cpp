#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // 如果存在a,b使a^2+b^2 = c^2
    // 那么 可以设计 0<=a<=b<=c
    // 双指针
    // 如果 a<b 且a^2+b^2<c^2
    // 一定有  a^2+(b-1)^2 < c^2，所以肯定是往大了变
    bool judgeSquareSum(int c) {
        int j = int(sqrt(c));

        for (int i = j; i >= 0; i--) {
            int x = c - i * i;
            int sqrtx = (int)sqrt(x);
            if (x == 0) {
                return true;
            } else if (sqrtx * sqrtx == x) {
                return true;
            }
        }

        return false;
    }
};

int main(int argc, char *argv[])
{
    Solution s;

    cout << (int)s.judgeSquareSum(2147482647) << endl;
    return 0;
}
