#include <iostream>
#include "Solution.h"

using namespace std;

int main()
{
    Solution su;
    vector<vector<int>> result = su.generateMatrix(4);
    for( auto vec : result)
    {
        for( auto x: vec)
            cout << x << "\t" << ends;
        cout << endl;
    }
    return 0;
}
