#include "Solution.h"
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    Solution su;
    vector<int> a({1,3,5,8});
    vector<int> b({2,5});
    std::cout << su.findMedianSortedArrays(a,b) << std::endl;
    return 0;
}
