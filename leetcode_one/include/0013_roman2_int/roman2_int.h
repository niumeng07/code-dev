/*
 * 把罗马数据转化为int型的阿拉伯数字。
 * 最大值最小问题 1 to 3999
 * 罗马数字规则：
 *    基本数字 I(1), V(5), X(10), L(50), C(100), D(500), M(1000), 
 * */
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    map<char, int> unit = { {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50 }, {'C', 100}, {'D', 500}, {'M', 1000} };
	int romanToInt(string s) 
	{
        int result = this->unit[s[s.length() - 1]];
        for( int i = 0; i < s.length() - 1; i++) {
            if(this->unit.find(char(s[i])) == this->unit.end()) return 0;
            if( this->unit[char(s[i])] >= this->unit[char(s[i+1])] ) 
                result += this->unit[s[i]];
            else
                result -= this->unit[s[i]];
        }
        return result;
	}
};
