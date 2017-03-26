/*
 * 输入: Int
 * 输出: 对应的罗马数字
 * 罗马数字规则：
 *    基本数字 I(1), V(5), X(10), L(50), C(100), D(500), M(1000), 
 * */
#include <iostream>
#include <string>
#include <map>

using namespace std;
class Solution {
public:
    map<char, int> unit = { {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50 }, {'C', 100}, {'D', 500}, {'M', 1000} };
    string intToRoman(int num) {
        // input: 3213
        // 1000*3 + 100*2 + 10*1 +1*3
        // 2800
        // 1000*2 + 500*1 + 100*3
        // 2900
        // 1000*2 +500*1 + 100*4   100*4可转化500*1 -100*1 = MMCM
        // 2999
        // 2000 + 900 + 90 +9 = 2000 + 1000 -100 + 100 -10 + 10-1 = MMCMXCIX 正确
        // 2499
        // 2000 + 400 +99 +9 = 2000 +500 -100 + 100 -10 + 10 -1 = MMCDXCIX  正确
        string result = "";
        int multi = 1;
        while(num != 0)
        {
            int tmp = ( num % 10 ) * multi;
            multi = multi * 10;
            num = num / 10;
        }
        return result;
    }
};
