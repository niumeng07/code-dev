#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    bool isMatch(string s, string p) {
        int i = 0, j = 0, s_len = s.length(), p_len = p.length();            
        if( p_len == 0 && s_len == 0 ) return true;
        if( p_len == 0 && s_len != 0 ) return false;
        if( char(p[0]) == '*' ) return false;
        bool flag = true;
        for( ; i < s_len && j < p_len; ){

        }
    }
};
