#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
bool isValid( vector<int> &t){ 
    for(int i = 0; i < t.size(); i++)
        for( int j = i + 1; j<t.size(); j++)
            if(abs(i - j) == abs(t[i] - t[j] ))
                return false;
    return true;
}
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string> > res;
        vector<int> t(n, 0);
        string s(n, '.');
        for(int i = 0; i<n; i++)
            t[i]=i;
        do {
            if( isValid(t) ){
                vector<string> v;
                for(int i = 0; i < t.size(); i++){
                    s[t[i]] = 'Q';
                    v.push_back(s);
                    s[t[i]] = '.';
                }
                res.push_back(std::move(v));
            }
        }while(std::next_permutation(t.begin(), t.end()));
        return res;
    }
};
