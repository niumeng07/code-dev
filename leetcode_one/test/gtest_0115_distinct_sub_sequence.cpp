#include "gtest/gtest.h"
#include <iostream>
#include <string>
#include "0115_distinct_sub_sequence/distinct_sub_sequence.h"
using namespace std;

int main()
{
    string S = "rabbbit";
    string T = "rabbit";
    Solution su;
    cout << su.numDistinct(S, T) << endl;
}
