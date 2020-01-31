#include "gtest/gtest.h"
#include <iostream>
#include "0020_valid_parentheses/valid_parentheses.h"
using namespace std;

int main()
{
    Solution su;
    if(su.isValid("]"))
        cout << "yes" << endl;
    else
        cout << "no" << endl;
    return 0;
}
