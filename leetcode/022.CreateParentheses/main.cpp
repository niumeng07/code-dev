#include <iostream>
#include "Solution.h"
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
