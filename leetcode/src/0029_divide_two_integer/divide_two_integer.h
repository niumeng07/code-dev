#include <glog/logging.h>
#include <limits.h>
#include <math.h>

#include <iostream>
using namespace std;

class DivideTwoInteger {
public:
    /* 以10*5为例，10*5=10*二进制[0101]=10*[100]+10*[001]
     * */
    DivideTwoInteger() {
        // google::InitGoogleLogging(argv[0]);
    }
    int multiply(int a, int b) {
        int y = 0;
        return 0;
    }
    int plus(int a, int b) {
        int x1 = (a ^ b);  // 4
        int x2 = (((a & b) | ((a & b) << 1)) << 1);
        int x3 = x2 ^ x1;
        cout << a << "\t" << b << "\t" << x1 << "\t" << x2 << "\t" << x3
             << endl;
        return x3;
    }
    int divide(int a, int b) {
        int flag = 1;
        if ((a < 0 && b > 0) || (a > 0 && b < 0)) flag = -1;
        a = abs(a);
        b = abs(b);
        unsigned int x, y;
        int ans = 0;
        while (a >= b) {
            x = b;
            y = 1;
            while (a >= (x << 1)) {
                x <<= 1;
                y <<= 1;
            }
            a -= x;
            ans += y;
        }
        ans = 0 - ans;
        return ans;
    }
};
void test() {
    cout << "3*7=21  =  ((3<<2)+(3<<1)+3)"
         << "=" << ((3 << 2) + (3 << 1) + 3) << endl;
}
