#include <iostream>
#include "Solution.h"

using namespace std;

int main()
{
    Solution su;
    cout << "1 a   " << su.isNumber("1 a") << endl;
    cout << "2e10   " << su.isNumber("2e10") << endl;
    cout << "abc   " << su.isNumber("abc") << endl;
    cout << "0.1   " << su.isNumber("0.1") << endl;
    cout << "123424   " << su.isNumber("123424") << endl;
    cout << "0   " << su.isNumber("0") << endl;
    cout << "e   " << su.isNumber("e") << endl;
    cout << ".   " << su.isNumber(".") << endl;
    cout << "-.   " << su.isNumber("-.") << endl;
    cout << ".-   " << su.isNumber(".-") << endl;
    cout << "6e6.5   " << su.isNumber("6e6.5") << endl;
    cout << ".1.   " << su.isNumber(".1.") << endl;
    cout << "+   " << su.isNumber("+") << endl;
    cout << ".1   " << su.isNumber(".1") << endl;
    cout << ".1e3   " << su.isNumber(".1e3") << endl;
    cout << "-2  " << su.isNumber("-2") << endl;
    cout << "1空格  " << su.isNumber("1 ") << endl;
    return 0;
}
