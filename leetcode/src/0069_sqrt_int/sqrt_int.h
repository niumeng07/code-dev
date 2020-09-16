#include <math.h>

#include <algorithm>
using namespace std;

class SqrtInt {
    /*
     * 牛顿法
     * 初始值x0
     * f(x_n)+f'(x_n)(deltax) = 0
     * f(x_n) + f'(x_n)(x_n+1 - x_n) =0
     * 得 x_n+1 = -f(x_n)/f'(x_n) + x_n
     * */
public:
    int mySqrt(int number) {
        if (number <= 0) return 0;
        double next = number / 2 + 1;
        while ((next * next - number) <= -1 || (next * next - number) >= 1) {
            next = (number + next * next) / (2 * next);
        }
        return next;
    }

    double iterSqrt(double number) {
        if (number <= 0) return 0;
        double s = number / 2.0;
        double epsilon = 0.001;
        while (abs(s * s - number) > epsilon) {
        }
        return s;
    }
};
