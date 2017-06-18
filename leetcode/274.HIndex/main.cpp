#include <iostream>
#include <vector>
#include "Solution.h"
using namespace std;
int main()
{
    Solution su;
    vector<int> input({1,1,2,2});
    cout << su.hIndex( input) << endl;
    return 0;
}
