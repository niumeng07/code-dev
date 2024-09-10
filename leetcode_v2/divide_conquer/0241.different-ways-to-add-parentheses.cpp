/*
给你一个由数字和运算符组成的字符串 expression ，按不同优先级组合数字和运算符，计算并返回所有可能组合的结果。你可以
按任意顺序 返回答案。
生成的测试用例满足其对应输出值符合 32 位整数范围，不同结果的数量不超过 104 。

示例 1：
输入：expression = "2-1-1"
输出：[0,2]
解释：
    ((2-1)-1) = 0
    (2-(1-1)) = 2

示例 2：
输入：expression = "2*3-4*5"
输出：[-34,-14,-10,-10,10]
解释：
    (2*(3-(4*5))) = -34
    ((2*3)-(4*5)) = -14
    ((2*(3-4))*5) = -10
    (2*((3-4)*5)) = -10
    (((2*3)-4)*5) = 10

提示：
1 <= expression.length <= 20
expression 由数字和算符 '+'、'-' 和 '*' 组成。
输入表达式中的所有整数值在范围 [0, 99]
*/

#include "header.h"

class Solution {
public:
    // 可以在任意位置添加括号
    // 分解，直到每个表达式的长度是1(除运算符号外)
    vector<int> results;
    int compute(vector<int>& nums, vector<char>& vec) {
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2 && vec.size() == 1) {
            if (vec[0] == '+') return nums[0] + nums[1];
            if (vec[0] == '-') return nums[0] - nums[1];
            if (vec[0] == '*') return nums[0] * nums[1];
        }
        // nums的长度>2, 进一步分治
        for (int i = 0; i < nums.size(); i++) {
        }
    }

    vector<int> diffWaysToCompute(string expression) {
        vector<int> nums;
        vector<char> vec;
        // 先把数字和符号分享出来
        for (int i = 0; i < expression.size();) {
            if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*') {  // 符号
                vec.push_back(expression[i]);
                i++;
            } else if (expression[i] >= '0' && expression[i] <= '9' && (i + 1) < expression.size() &&
                       expression[i + 1] >= '0' && expression[i + 1] <= '9') {  // 两位数字
                string tmp_num = expression.substr(i, 2);
                nums.push_back(stoi(tmp_num));
                i += 2;
            } else if (expression[i] >= '0' && expression[i] <= '9') {  // 一位数字
                nums.push_back(expression[i] - '0');
                i++;
            } else {  // 应该不会有这里
                cout << "error" << endl;
            }
        }
        // 分治
        return results;
    }
};

int main(int argc, char *argv[]) {
    print_vector(Solution().diffWaysToCompute("2*3-4*50"));
    return 0;
}
