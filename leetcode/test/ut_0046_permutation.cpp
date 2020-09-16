#include <iostream>
#include <vector>

#include "0046_permutation/permutation.h"
#include "gtest/gtest.h"
using namespace std;
int main(int argc, char **argv) {
    Permutation su;
    vector<int> in({1, 0, -1});
    vector<vector<int> > res = su.permute(in);
    for (auto v : res) {
        for (auto x : v) cout << x << ", ";
        cout << endl;
    }
    return 0;
}
