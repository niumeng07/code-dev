#include "gtest/gtest.h"
#include <string>
#include <vector>
#include "0539_min_time_diff/min_time_diff.h"

int main()
{
    Solution su;
    std::vector<string> vec;
    vec.push_back("01:01");
    vec.push_back("02:01");
    vec.push_back("03:00");
    cout << su.findMinDifference(vec) << endl;
    return 0;
}
