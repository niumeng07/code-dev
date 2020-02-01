#include "gtest/gtest.h"
#include "0013_roman2_int/roman2_int.h"
#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    Roman2Int su;
    cout << su.romanToInt("III") << "\n" << 
    su.romanToInt("XCIX") << "\n" <<
    su.romanToInt("XC") << "\n" <<  
    su.romanToInt("MMMCCCXXXIII") << "\n"<< 
    su.romanToInt("ABC") << "\n";
    return 0;
}
