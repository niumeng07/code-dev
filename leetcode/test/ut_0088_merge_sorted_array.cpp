#include "gtest/gtest.h"
#include <iostream>
#include <vector>
#include "0088_merge_sorted_array/merge_sorted_array.h"

using namespace std;

int main(int argc, char **argv)
{
    MergeSortedArray2 su;
    vector<int> v1({1,2,5,8,8,10,11,12});
    vector<int> v2({3,4,4,8,9,15});
    su.merge(v1, v1.size(), v2, v2.size());
    for(auto x : v1)
        cout << x << " ";
    cout << endl;
    return 0;
}
