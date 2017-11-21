#include <vector>
#include <iostream>
#include "Solution.h"
using namespace std;
int main()
{
    Solution su;
    vector<int> input({-2,1,-3,4,-1,2,1,-5,4});
    cout << su.maxSubArray(input) << endl;
    return 0;
}
