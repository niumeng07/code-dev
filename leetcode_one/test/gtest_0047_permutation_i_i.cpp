#include "gtest/gtest.h"
#include <iostream>
#include <vector>
#include <time.h>
#include "0047_permutation_i_i/permutation_i_i.h"

using namespace std;

int main()
{
    Solution su;
    clock_t start, end;
    vector<int> nums({3,3,0,0,2,3,2});
    start = clock();
    vector<vector<int> > res = su.permuteUnique(nums);
    end = clock();
    for(auto vec : res)
    { 
        for( auto x : vec )
            cout << x << " ";
        cout << endl;
    }
    cout << "permuteUnique time: " << end - start << endl;
    return 0;
}
