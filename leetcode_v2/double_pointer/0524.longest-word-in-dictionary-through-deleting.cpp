#include "header.h"

/* 给你一个字符串 s 和一个字符串数组 dictionary ，找出并返回 dictionary 中最长的字符串，该字符串可以通过删除 s
 * 中的某些字符得到。
 *
 * 如果答案不止一个，返回长度最长且字母序最小的字符串。如果答案不存在，则返回空字符串。
 *
 * 示例 1：
 * 输入：s = "abpcplea", dictionary = ["ale","apple","monkey","plea"]
 * 输出："apple"
 *
 * 示例 2：
 * 输入：s = "abpcplea", dictionary = ["a","b","c"]
 * 输出："a"
 * */

/* 问题分析
 * 问题变成了在s中能否依次找到dictionary中的...
 * 子串问题
 * */

class Solution {
public:
    bool isSubStr(const string& s, const string& t, size_t i = 0, size_t j = 0) {
        if (j >= t.size()) {
            return true;
        } else if (i >= s.size()) {
            return false;
        }
        if (s[i] == t[j]) {
            return isSubStr(s, t, i + 1, j + 1);
        } else {
            return isSubStr(s, t, i + 1, j);
        }
    }
    string findLongestWord(string s, vector<string>& dictionary) {
        string result = "";
        for (const auto& target : dictionary) {
            bool issubstr = isSubStr(s, target);

            if (issubstr && target.size() > result.size()) {
                result = target;
            } else if (issubstr && target.size() == result.size()) {
                // 比较字母序，返回字母序较小的一个
                if (target < result) {
                    result = target;
                }
            }
        }
        return result;
    }
};

int main(int argc, char* argv[]) {
    Solution solution;

    vector<string> dictionary = {"ale", "apple", "monkey", "plea"};
    string result = solution.findLongestWord("abpcplea", dictionary);
    cout << result << endl;

    dictionary = {"abe","abc"};
    result = solution.findLongestWord("abce", dictionary);
    cout << result << endl;

    return 0;
}
