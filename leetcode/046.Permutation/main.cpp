#include <iostream>
#include "Solution.h"
#include <vector>
using namespace std;
int main()
{
    Solution su;
    vector<int> in({1,0,-1});
    vector<vector<int> > res = su.permute(in);
    for(auto v : res)
    {
        for(auto x :v )
            cout << x << ", ";
        cout << endl;
    }
    return 0;
}