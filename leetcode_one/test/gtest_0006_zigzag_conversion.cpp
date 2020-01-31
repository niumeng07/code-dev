#include "gtest/gtest.h"
#include <iostream>
#include "0006_zigzag_conversion/zigzag_conversion.h"
using namespace std;

int main()
{
    Solution su;
    if( su.convert("PAYPALISHIRING", 3) == "PAHNAPLSIIGYIR")
        cout << "pass." << endl;
    else
        cout << "error." << endl;
    cout << " ------------------------------ " << endl;
    if( su.convert("", 3) == "")
        cout << "pass." << endl;
    else
        cout << "error." << endl;
    cout << " ------------------------------ " << endl;
    if( su.convert("A", 2) == "A")
        cout << "pass." << endl;
    else
        cout << "error." << endl;
    cout << " ------------------------------ " << endl;
    if( su.convert("ABC", 2) == "ACB")
        cout << "pass." << endl;
    else
        cout << "error." << endl;
    cout << " ------------------------------ " << endl;
    if( su.convert("AB", 2) == "AB")
        cout << "pass." << endl;
    else
        cout << "error." << endl;
    cout << " ------------------------------ " << endl;
    if( su.convert("ABCD", 2) == "ACBD")
        cout << "pass." << endl;
    else
        cout << "error." << endl;
}
