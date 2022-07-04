#include <iostream>
#include <vector>

#include "0039_combination_sum/combination_sum.h"
#include "gtest/gtest.h"
using namespace std;

int main(int argc, char **argv) {
    // CombinationSum su;
    vector<int> in({2, 3, 6, 7});
    // vector<vector<int> > res = su.combinationSum(in, 7);
    // for (auto v : res) {
    //     for (auto x : v) cout << x << "  ";
    //     cout << endl;
    // }
    // Solution().combinationSum(in, 7);
    in = {2,3,5};
    Solution().combinationSum(in, 8);
    return 0;
}
