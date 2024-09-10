/*
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
每个右括号都有一个对应的相同类型的左括号。

示例 1：
输入：s = "()"
输出：true

示例 2：
输入：s = "()[]{}"
输出：true

示例 3：
输入：s = "(]"
输出：false

示例 4：
输入：s = "([])"
输出：true
*/

#include "header.h"
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (int i = 0; i < s.size(); i++) {
            if (stk.empty() && (s[i] == '(' || s[i] == '[' || s[i] == '{')) {
                stk.push(s[i]);
            } else if (stk.empty()) {
                return false;
            } else if (s[i] == '(' || s[i] == '[' || s[i] == '{') { // 之后: stk不为空
                stk.push(s[i]);
            } else if (s[i] == ')') {
                if (stk.top() == '(') {
                    stk.pop();
                } else {
                    return false;
                }
            } else if (s[i] == ']') {
                if (stk.top() == '[') {
                    stk.pop();
                } else {
                    return false;
                }

            } else if (s[i] == '}') {
                if (stk.top() == '{') {
                    stk.pop();
                } else {
                    return false;
                }

            }
        }
        return stk.empty();
    }
};

int main(int argc, char *argv[])
{
    cout << Solution().isValid("()") << "\t标准答案: " << true << endl;
    cout << Solution().isValid("()[]{}") << "\t标准答案: " << true << endl;
    cout << Solution().isValid("(]") << "\t标准答案: " << false << endl;
    cout << Solution().isValid("([])") << "\t标准答案: " << true << endl;
    return 0;
}
