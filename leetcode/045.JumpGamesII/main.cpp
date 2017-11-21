#include <iostream>
#include <vector>
#include "Solution.h"
using namespace std;
int main()
{
    Solution su;
    vector<int> steps({2,3,1,1,4});
    cout << su.jump(steps) << endl;
    return 0;
}
