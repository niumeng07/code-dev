#include "gtest/gtest.h"
#include <iostream>
#include <vector>
#include "0274_h_index/h_index.h"
using namespace std;
int main()
{
    Solution su;
    vector<int> input({1,1,2,2});
    cout << su.hIndex( input) << endl;
    return 0;
}
