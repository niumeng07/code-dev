#include <iostream>
#include "Solution.h"
using namespace std;
int main()
{
    Solution su;
    cout << su.divide( 4,2) << endl;
    cout << su.divide( 14,3) << endl;
    cout << su.divide( -14,3) << endl;
    cout << su.divide( -14,-3) << endl;
    cout << su.divide( 1,0) << endl;
    cout << su.divide(2147483647,1) << endl;
    cout << su.divide(-2147483648,-1) << endl;
}
