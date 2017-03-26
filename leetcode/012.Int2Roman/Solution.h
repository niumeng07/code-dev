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
    }
};
