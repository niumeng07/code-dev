#include "gtest/gtest.h"
#include "0532_diff_pairs_in_array/diff_pairs_in_array.h"
#include <iostream>

int main() {
    Solution su;
    vector<int> v = {7, 5, 16, 8, 10};
    cout << su.findPairs(v, 2) << endl;
    v = {3, 1, 4, 1, 5};
    cout << su.findPairs(v, 2) << endl;
    v = {1, 2, 3, 4, 5};
    cout << su.findPairs(v, 1) << endl;
    v = {1, 3, 1, 5, 4};
    cout << su.findPairs(v, 0) << endl;
    v = {1};
    cout << su.findPairs(v, 0) << endl;
    cout << "-----------------------------------------" << endl;
    v = {1, 2, 3, 4, 5};
    cout << su.findPairs(v, -1) << endl;
    return 0;
}
