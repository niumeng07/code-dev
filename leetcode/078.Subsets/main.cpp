#include <vector>
#include <iostream>
#include "Solution.h"
using namespace std;
int main()
{
    Solution su;
    vector<int> input({1,2,3});
    vector<vector<int> > subsets = su.subsets(input);
    for(auto vec : subsets)
    {
        for(auto i : vec)
            cout << i << "\t";
        cout << endl;
    }
    return 0;
}
