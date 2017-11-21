#include <iostream>
#include <string>
#include "Solution.h"
using namespace std;

int main()
{
    string S = "rabbbit";
    string T = "rabbit";
    Solution su;
    cout << su.numDistinct(S, T) << endl;
}
