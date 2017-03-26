#include "Solution.h"
#include <iostream>
using namespace std;

int main()
{
    Solution su;
    su.isMatch("aa", "a");
    su.isMatch("aa", "aa");
    su.isMatch("aaa", "aa");
    su.isMatch("aa", "a*");

    return 0;
}
