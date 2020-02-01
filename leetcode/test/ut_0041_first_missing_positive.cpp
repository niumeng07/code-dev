#include "gtest/gtest.h"
#include <iostream>
#include "0041_first_missing_positive/first_missing_positive.h"
#include <vector>
#include <time.h>

using namespace std;
int main(int argc, char **argv)
{
    clock_t start, end, s2, e2;
    vector<int> nums({ 1,2,2,1,3,1,0,4,0 });
    nums = {0};
    nums = {0};
    FirstMissingPositive su;
    start = clock();
    int x1 = su.firstMissingPositive(nums);
    end = clock();
    s2 = clock();
    int x2 = su.firstMissingPositive2(nums);
    e2 = clock();
    cout << x1 << " time: " << end - start << endl;
    cout << x2 << " time: " << e2 - s2 << endl;
    return 0;
}
