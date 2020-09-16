#include <iostream>
#include <vector>

#include "0078_subsets/subsets.h"
#include "gtest/gtest.h"
using namespace std;
int main(int argc, char **argv) {
    Subsets su;
    vector<int> input({1, 2, 3});
    vector<vector<int> > subsets = su.subsets(input);
    for (auto vec : subsets) {
        for (auto i : vec) cout << i << "\t";
        cout << endl;
    }
    return 0;
}
