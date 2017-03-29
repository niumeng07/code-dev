#include "Solution.h"
#include <iostream>
#include <vector>
#include <limits>
using namespace std;

int main()
{
    Solution su;
    su.reverse(-123);
    su.reverse(0);
    su.reverse(1);
    su.reverse(2);
    su.reverse(10);
    su.reverse(-345567);
    su.reverse(-3459567);
    su.reverse(1323);
    cout << "1534236469  " << su.reverse(1534236469) << endl;
    return 0;
}
