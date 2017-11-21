#include <vector>
#include <iostream>
#include "Solution.h"

using namespace std;

int main()
{
    Solution su;
    vector<int> v({2,0,1,2,1,2,1,1,1,0,0});
    su.sortColors(v);
    for(auto x : v)
        cout << x << ", ";
    cout << endl;
    return 0;
}
