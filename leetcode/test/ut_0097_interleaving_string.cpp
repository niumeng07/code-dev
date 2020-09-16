#include <iostream>

#include "0097_interleaving_string/interleaving_string.h"
#include "gtest/gtest.h"
using namespace std;

int main(int argc, char **argv) {
    InterleavingString su;
    /*
    cout << su.isInterleave("abc", "def", "adebcf") << endl;
    cout << su.isInterleave("abc", "def", "adbcfe") << endl;
    cout << su.isInterleave("", "def", "def") << endl;
    cout << su.isInterleave("", "def", "adef") << endl;
    cout << su.isInterleave("", "", "") << endl;
    cout << su.isInterleave("", "", "adef") << endl;
    cout << su.isInterleave("abcdefghi", "", "abcdefghi") << endl;
    cout << su.isInterleave("aa", "ab", "aaba") << endl;

    return 0;
    */
    clock_t start, end;
    start = clock();
    string a =
            "bbbbbabbbbabaababaaaabbababbaaabbabbaaabaaaaababbbababbbbbabbbbaba"
            "bbabaabababbbaabababababbbaaababaa";
    string b =
            "babaaaabbababbbabbbbaabaabbaabbbbaabaaabaababaaaabaaabbaaabaaaabaa"
            "baabbbbbbbbbbbabaaabbababbabbabaab";
    string c =
            "babbbabbbaaabbababbbbababaabbabaabaaabbbbabbbaaabbbaaaaabbbbaabbaa"
            "abababbaaaaaabababbababaababbababbbababbbbaaaabaabbabbaaaaabbabbaa"
            "aabbbaabaaabaababaababbaaabbbbbabbbbaabbabaabbbbabaaabbababbabbabb"
            "ab";
    cout << a.size() << "  " << b.size() << "  " << c.size() << endl;
    cout << a.length() << "  " << b.length() << "  " << c.length() << endl;
    /*
    string a = "bbbbbabbbbabaababaaaabbababbaaabbabbaaabaaaaa";
    string b = "baaaabaaabbaaabaaaabaabaabbbbbbbbbbbabaaabbababbabbabaab";
    string c =
    "bbbbbbabbbbabaaaabaaabbaaaababaaaabbababbaaaabaaaabaabaabbbbbbbbbabbaaababbbbabaaabbababbabbaaaaabaab";
    */
    cout << su.isInterleaveDP(a, b, c) << endl;
    end = clock();
    cout << "time used " << end - start << endl;
    return 0;
}
