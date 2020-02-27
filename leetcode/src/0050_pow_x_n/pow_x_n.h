/**
 * @file pow_x_n.h
 * @brief
 *   Implement pow(x, n).
 * @author myliuda@sina.com
 * @version 0.0.1
 * @date 2020-02-08
 */
#include <iostream>
#include <math.h>
using namespace std;
class PowXN {
public:
  double Pow(double x, int n) { return pow(x, n); }

  double myPow(double x, int n) {
    if (n == 0)
      return 1;
    if (n == 1)
      return x;
    if (n == 2)
      return x * x;
    if (n % 2 == 0)
      return myPow(x * x, n / 2);
    if (n % 2 == 1)
      return myPow(x * x, n / 2) * x;
    return 0.0;
  }
  double forPow(double x, int n) {
    if (n == 0)
      return 1;
    if (n == 1)
      return x;
    double y = 1;
    for (int i = 0; i < n; i++) {
      y = y * x;
    }
    return y;
  }
};
