#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;
bool sfun(vector<string> &a, vector<string> &b)
{
    return a.size() < b.size();
}
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string> > res;        

        map<string, vector<string> > m;
        vector<string> tmp;

        for(auto word : strs)
        {
            sort(word.begin(), word.end());
            m[word] = tmp;
        }
        string st;
        for(auto word : strs)
        {
            st=word;
            sort(st.begin(), st.end());
            m[st].push_back(word);
        }
        for(auto iter = m.begin(); iter != m.end(); iter++)
        {
            sort(iter->second.begin(), iter->second.end());
            res.push_back(std::move(iter->second));
        }
        sort(res.begin(), res.end(), sfun);
        return res;
    }
};
