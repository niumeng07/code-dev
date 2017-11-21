#include <iostream>
#include <vector>
#include "Solution.h"

using namespace std;

int main()
{
    Solution2 su;
    vector<int> v1({1,2,5,8,8,10,11,12});
    vector<int> v2({3,4,4,8,9,15});
    su.merge(v1, v1.size(), v2, v2.size());
    for(auto x : v1)
        cout << x << " ";
    cout << endl;
    return 0;
}
