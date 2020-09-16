#include <iostream>
#include <string>
using namespace std;
class RegularMatching {
public:
    bool isMatch(string s, string p) {
        if (p.empty()) return s.empty();
        if (char(p[p.length() - 1]) == '*' &&
            (char(s[s.length() - 1]) == char(p[p.length() - 2]) ||
             (char(p[p.length() - 2]) == '.')))  // p未位为*
            return (!s.empty())
                           ? isMatch(s, p.substr(0, p.length() - 2)) ||
                                     isMatch(s.substr(0, s.length() - 1),
                                             p.substr(0, p.length() - 2)) ||
                                     isMatch(s.substr(0, s.length() - 1), p)
                           : isMatch(s, p.substr(0, p.length() - 2));
        if (char(p[p.length() - 1]) == '*' &&
            char(s[s.length() - 1]) != char(p[p.length() - 2]))  // p未位为*
            return isMatch(s.substr(0, s.length()),
                           p.substr(0, p.length() - 2));
        if (char(p[p.length() - 1]) == '.')  // p未位. 同时截掉最后一位比较
            return (s.empty()) ? false
                               : isMatch(s.substr(0, s.length() - 1),
                                         p.substr(0, p.length() - 1));
        if (char(p[p.length() - 1]) != '.' &&
            char(p[p.length() - 1]) !=
                    '*')  // p未尾非.非*  同时把最后一位截掉后比较
            return (p[p.length() - 1] == s[s.length() - 1])
                           ? isMatch(s.substr(0, s.length() - 1),
                                     p.substr(0, p.length() - 1))
                           : false;
        return false;
    }
};
