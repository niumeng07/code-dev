#include "gtest/gtest.h"
#include <iostream>
#include "0039_combination_sum/combination_sum.h"
#include <vector>
using namespace std;

int main(int argc, char **argv)
{
    CombinationSum su;
    vector<int> in({2, 3, 6, 7});
    vector<vector<int> > res = su.combinationSum(in, 7);
    for( auto v : res)
    {
        for( auto x : v)
            cout << x << "  ";
        cout << endl;
    }
    return 0;
}
