#include <iostream>
#include <vector>

#include "0053_max_sub_array/max_sub_array.h"
#include "gtest/gtest.h"
using namespace std;
int main(int argc, char **argv) {
    MaxSubArray su;
    vector<int> input({-2, 1, -3, 4, -1, 2, 1, -5, 4});
    cout << su.maxSubArray(input) << endl;
    return 0;
}
