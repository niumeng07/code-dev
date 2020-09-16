#include <iostream>

#include "0215_kth_large_num/kth_large_num.h"
#include "gtest/gtest.h"

int main(int argc, char **argv) {
    KthLargeNum su;
    vector<int> input({3, 2, 1, 5, 6, 4});
    cout << su.findKthLargest(input, 2) << endl;
    cout << su.findKthLargest2(input, 2) << endl;
    return 0;
}
