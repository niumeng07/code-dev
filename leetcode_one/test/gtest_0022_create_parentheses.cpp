#include "gtest/gtest.h"
#include <iostream>
#include "0022_create_parentheses/create_parentheses.h"
#include <vector>

using namespace std;
int main()
{
    Solution su;
    vector<string> result = su.generateParenthesis(3);
    for (auto x : result)
        cout << x << "\t" << ends;
    cout << endl;
    return 0;
}
