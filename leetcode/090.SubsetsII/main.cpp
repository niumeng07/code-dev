#include "Solution.h"
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    Solution su;
    vector<int> nums({1,2,2});
    clock_t start, end;
    start = clock();
    vector<vector<int> > result = su.subsetsWithDup(nums);
    end = clock();
    cout << end - start<< endl;
    for(auto vec : result)
    {
        cout << "[ " ;
        for(auto x : vec)
            cout << x << ", ";
        cout << "]" << endl;
    }
    return 0;
}