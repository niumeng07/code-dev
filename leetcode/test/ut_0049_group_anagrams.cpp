#include "gtest/gtest.h"
#include <iostream>
#include <vector>
#include <string>
#include "0049_group_anagrams/group_anagrams.h"

using namespace std;

int main(int argc, char **argv)
{
    GroupAnagrams su;
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
