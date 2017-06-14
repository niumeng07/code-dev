#include <iostream>
#include <vector>
#include <string>
#include "Solution.h"

using namespace std;

int main()
{
    Solution su;
    vector<string> strs({"eat", "tea", "tan", "ate", "nat", "bat"});
    vector<vector<string> > res = su.groupAnagrams(strs);

    for(auto vec : res)
    {
        for( auto x : vec)
            cout << x << " ";
        cout << endl;
    }
    return 0;
}
