#include <iostream>
using namespace std;

// 正则表达式
class Solution {
public:
    string process(string s) {
        if (s.empty()) return s;
        string ret;
        char x = s[0];
        ret.push_back(x);
        for (int i = 1; i < s.size(); i++) {
            if (x=='*' && s[i]=='*') {
            } else {
                ret.push_back(s[i]);
                x = s[i];
            }
        }
        return ret;
    }
    bool isMatch(string s, string p) {
        s = process(s);
        p = process(p);
        return isMatchImp(s, p);
    }
    bool isMatchImp(string s, string p) {
        if (s.empty()) {
            return p.empty() || (p[0] == '*' && isMatchImp(s, p.substr(1, p.size() - 1)));
        }
        if (p.empty()) {
            return s.empty() || (s[0] == '*' && isMatchImp(s.substr(1, s.size() - 1), p));
        }
        if (s.size() == 1 && p.size() == 1) {
            return s == p || s[0] == '?' || p[0] == '?' || s[0] == '*' ||
                   p[0] == '*';
        }
        // s,p均非空
        if (s[0] != '*' && p[0] != '*') {  // s[0], p[0]都不是*
            return (s[0] == p[0] || s[0] == '?' || p[0] == '?') &&
                   isMatchImp(s.substr(1, s.size() - 1),
                           p.substr(1, p.size() - 1));
        } else if (s[0] == '*' && p[0] == '*') {  // s[0], p[0]都是*
            for (int i = 0; i <= s.size(); i++) {
                if (isMatchImp(s.substr(i, s.size() - i),
                            p.substr(1, p.size() - 1)))
                    return true;
            }
            for (int i = 0; i <= s.size(); i++) {
                if (isMatchImp(p.substr(i, p.size() - i),
                            s.substr(1, s.size() - 1)))
                    return true;
            }
        } else if (s[0] == '*') {  // s[0] == '*', p[0] != '*'
            for (int i = 0; i <= s.size(); i++) {
                if (isMatchImp(p.substr(i, p.size() - i),
                            s.substr(1, s.size() - 1)))
                    return true;
            }
        } else {  // s[0] != '*', p[0] == '*'
            for (int i = 0; i <= s.size(); i++) {
                if (isMatchImp(s.substr(i, s.size() - i),
                            p.substr(1, p.size() - 1)))
                    return true;
            }
        }

        return false;
    }
};

/* Given an input string (s) and a pattern (p), implement wildcard pattern
 matching with support for '?' and '*'.

 * '?' Matches any single character.
 * '*' Matches any sequence of characters (including the empty sequence).
 * The matching should cover the entire input string (not partial).
 *
 * Note:
 *
 * s could be empty and contains only lowercase letters a-z.
 * p could be empty and contains only lowercase letters a-z, and characters like
 ? or *.
 *
 * Example 1:
 *    Input:
 *      s = "aa"
 *      p = "a"
 *    Output: false
 *    Explanation: "a" does not match the entire string "aa".
 *
 * Example 2:
 *    Input:
 *      s = "aa"
 *      p = "*"
 *    Output: true
 *    Explanation: '*' matches any sequence.
 *
 * Example 3:
 *    Input:
 *      s = "cb"
 *      p = "?a"
 *    Output: false
 *    Explanation: '?' matches 'c', but the second letter is 'a', which does not
 match 'b'.
 *
 * Example 4:
 *    Input:
 *      s = "adceb"
 *      p = "*a*b"
 *    Output: true
 *    Explanation: The first '*' matches the empty sequence, while the second
 '*' matches the substring "dce".
 *
 * Example 5:
 *    Input:
 *      s = "acdcb"
 *      p = "a*c?b"
 *    Output: false
 * */
