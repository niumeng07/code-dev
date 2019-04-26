#include <iostream>
#include <limits.h>
#include <math.h>
using namespace std;

class Solution {
public:
  int divide(int a, int b) {
    int flag = 1;
    if ((a < 0 && b > 0) || (a > 0 && b < 0))
      flag = -1;
    a = abs(a);
    b = abs(b);
    unsigned int x, y;
    int ans = 0;
    while (a >= b) {
      x = b;
      y = 1;
      cout << x << "\t" << y << endl;
      while (a >= (x << 1)) {
        x <<= 1;
        y <<= 1;
        cout << x << "\t" << y << endl;
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
