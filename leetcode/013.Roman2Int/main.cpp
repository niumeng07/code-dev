#include "Solution.h"
#include <iostream>
using namespace std;

int main()
{
    Solution su;
    cout << su.romanToInt("III") << "\n" << 
    su.romanToInt("XCIX") << "\n" <<
    su.romanToInt("XC") << "\n" <<  
    su.romanToInt("MMMCCCXXXIII") << "\n"<< 
    su.romanToInt("ABC") << "\n";
    return 0;
}
