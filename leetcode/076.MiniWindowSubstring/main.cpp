#include <iostream>
#include <string>
#include "Solution.h"
using namespace std;
int main()
{
    string s = "ADOBECODEBANC";
    string t = "ABC";
    Solution su;
    cout <<  su.minWindow(s, t) << endl;
}
