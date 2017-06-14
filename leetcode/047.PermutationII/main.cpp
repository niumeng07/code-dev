#include <iostream>
#include <vector>
#include "Solution.h"

using namespace std;

int main()
{
    Solution su;
    vector<int> nums;
    vector<vector<int> > res = su.permuteUnique(nums);
    for(auto vec : res)
    { 
        for( auto x : vec )
            cout << x << " ";
        cout << endl;
    }
    return 0;
}
