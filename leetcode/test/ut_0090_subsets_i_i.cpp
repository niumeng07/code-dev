#include <iostream>
#include <vector>

#include "0090_subsets_i_i/subsets_i_i.h"
#include "gtest/gtest.h"
using namespace std;

int main(int argc, char **argv) {
    SubsetsII su;
    vector<int> nums({1, 2, 2});
    clock_t start, end;
    start = clock();
    vector<vector<int> > result = su.subsetsWithDup(nums);
    end = clock();
    cout << end - start << endl;
    for (auto vec : result) {
        cout << "[ ";
        for (auto x : vec) cout << x << ", ";
        cout << "]" << endl;
    }
    return 0;
}
