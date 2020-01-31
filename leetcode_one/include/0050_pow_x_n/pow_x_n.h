#include <iostream>
#include <math.h>
using namespace std;
class Solution 
{
public:
    double myPow(double x, int n) 
    {
        return pow(x, n);
        if( n % 2 == 0)
            return pow(x*x, n/2);
        return pow(x*x, (n-1)/2) * x;
    }
};
