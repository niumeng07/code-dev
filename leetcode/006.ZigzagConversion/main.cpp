#include <iostream>
#include "Solution.h"
using namespace std;

int main()
{
    Solution su;
    string tmp = "PAYPALISHIRING";
    cout << tmp.substr(0, 1 ) << endl;
    if( su.convert("PAYPALISHIRING", 3) == "PAHNAPLSIIGYIR")
        cout << "pass." << endl;
    else
        cout << "error." << endl;
}
