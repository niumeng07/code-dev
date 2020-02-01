#include "gtest/gtest.h"
#include <iostream>
#include "0069_sqrt_int/sqrt_int.h"

int main(int argc, char **argv)
{
    SqrtInt su;
    cout << "0: " << su.mySqrt(0) << endl;
    cout << "1: " <<su.mySqrt(1) << endl;
    cout << "2: " <<su.mySqrt(2) << endl;
    cout << "3: " <<su.mySqrt(3) << endl;
    cout << "4: " <<su.mySqrt(4) << endl;
    cout << "5: " <<su.mySqrt(5) << endl;
    cout << "7: " <<su.mySqrt(7) << endl;
    cout << "10: " <<su.mySqrt(10) << endl;
    cout << "91: " <<su.mySqrt(91) << endl;
    cout << "100: " <<su.mySqrt(100) << endl;
    cout << "981001: " <<su.mySqrt(981001) << endl;
    return 0;
}
