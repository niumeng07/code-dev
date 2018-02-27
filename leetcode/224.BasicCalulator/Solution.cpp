#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <ctype.h>
#include <stdio.h>
using namespace std;

class Solution {
public:
    /* 思路
     * 1. 去括号
     * 2. 计算
     * */
	int calculate(string s) {
        stack <int> nums, ops;
        int num = 0;
        int rst = 0;
        int sign = 1;
        for (char c : s) { 
            if (isdigit(c)) {
                num = num * 10 + c - '0';
            }
            else {
                rst += sign * num;
                num = 0;
                if (c == '+') sign = 1;
                if (c == '-') sign = -1;
                if (c == '(') {
                    nums.push(rst);
                    ops.push(sign);
                    rst = 0;
                    sign = 1;
                }
                if (c == ')' && ops.size()) {
                    rst = ops.top() * rst + nums.top();
                    ops.pop(); nums.pop();
                }
            }
        }
        rst += sign * num;
        return rst;
    }
};
int main(){
	string input = "(1+(4+5+2)-3)+(6+8)";
	string input2 = "2147483647";//2147483647
	string input3 = "2-(5-6)";
    Solution su;
    cout << su.calculate(input) << endl;
    cout << su.calculate(input2) << endl;
    cout << su.calculate(input3) << endl;
}
/*
(, 1, +, (, 4, +, 5, +, 2, ), -, 3, ), +, (, 6, +, 8, ),
2147483647,
2, -, (, 5, -, 6, ),
*/
