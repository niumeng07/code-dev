/*
 * 输入: Int
 * 输出: 对应的罗马数字
 * 罗马数字规则：
 *    基本数字 I(1), V(5), X(10), L(50), C(100), D(500), M(1000), 
 * */
#include <iostream>
#include <string>

using namespace std;
class Int2Roman {
public:
    string intToRoman(int num) {
        string unit_one[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        string unit_ten[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        string unit_hud[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        string unit_tho[] = {"", "M", "MM", "MMM", "MMMM"};
        string result = unit_tho[num/1000] + unit_hud[num%1000/100] + unit_ten[num%100/10] + unit_one[num%10];
        return result;
    }
};
