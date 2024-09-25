/* 给你一个由数字和运算符组成的字符串 expression ，按不同优先级组合数字和运算符，计算并返回所有可能组合的结果。你可以
 * 按任意顺序 返回答案。
 * 生成的测试用例满足其对应输出值符合 32 位整数范围，不同结果的数量不超过 104 。
 *
 * 示例 1：
 * 输入：expression = "2-1-1"
 * 输出：[0,2]
 * 解释：
 *     ((2-1)-1) = 0
 *     (2-(1-1)) = 2
 *
 * 示例 2：
 * 输入：expression = "2*3-4*5"
 * 输出：[-34,-14,-10,-10,10]
 * 解释：
 *     (2*(3-(4*5))) = -34
 *     ((2*3)-(4*5)) = -14
 *     ((2*(3-4))*5) = -10
 *     (2*((3-4)*5)) = -10
 *     (((2*3)-4)*5) = 10
 *
 * 提示：
 * 1 <= expression.length <= 20
 * expression 由数字和算符 '+'、'-' 和 '*' 组成。
 * 输入表达式中的所有整数值在范围 [0, 99]
 * */

#include "header.h"

int op(int left, int right, int symbol) {
    if (symbol == -1) return left + right;
    if (symbol == -2) return left - right;
    if (symbol == -3) return left * right;
    if (symbol == -4) return left / right;
    return 0;
}

class Solution {
public:
    // 可以在任意位置添加括号
    // 分解，直到每个表达式的长度是1(除运算符号外)
    vector<int> results;
    unordered_map<char, int> symbols = {{'+', -1}, {'-', -2}, {'*', -3}, {'/', -4}};
    vector<vector<int>> matrix;  // 存储nums的i~j构成的表达式有几种解法

    int binary_sum(vector<int>& nums, int start, int end) {
        if (start >= nums.size()) {
            return 0;
        }
        if (start == end) {  // 只有一个数字了，不能再分了
            matrix[start][end] = nums[start];
            // 需要在这里push results
            return matrix[start][end];
        }
        for (int i = start; i < end; i += 2) {  // i+=2循环跳过运算符
            int middle = (start + end) / 2;
            int left = binary_sum(nums, start, middle - 1);
            int right = binary_sum(nums, middle + 1, end);  // 相当于把前后分别用括号括起来
            matrix[start][end] = op(left, right, nums[middle]);
            // results.push_back(matrix[start][end]);
        }
        return 0;
    }

    vector<int> diffWaysToCompute(string expression) {
        vector<int> nums;
        // 先把数字和符号分享出来
        for (int i = 0; i < expression.size();) {
            if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*') {  // 符号
                nums.push_back(symbols[expression[i]]);
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
        // print_vector(nums);
        // 分治, 用任意标点符号把表达式分成两两部分
        matrix = vector<vector<int>>(nums.size(), vector<int>(nums.size(), -10));
        binary_sum(nums, 0, nums.size() - 1);
        return results;
    }
};

int main(int argc, char* argv[]) {
    print_vector(Solution().diffWaysToCompute("2*3-4*50"));
    return 0;
}
