#include <iostream>

#include "0710_random_pickwith_blacklist/random_pickwith_blacklist.h"
#include "gtest/gtest.h"
using namespace std;

int main(int argc, char **argv) {
    vector<int> B({1, 2, 3});
    uint32_t N = 1000000000;
    RandomPickwithBlacklist *su = new RandomPickwithBlacklist(N, B);
    // cout << su->pick() << endl;
    return 0;
}