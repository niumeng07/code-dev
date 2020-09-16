#include <iostream>

#include "0020_valid_parentheses/valid_parentheses.h"
#include "gtest/gtest.h"
using namespace std;

int main(int argc, char **argv) {
    ValidParentheses su;
    if (su.isValid("]"))
        cout << "yes" << endl;
    else
        cout << "no" << endl;
    return 0;
}
