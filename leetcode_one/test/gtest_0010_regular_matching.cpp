#include "gtest/gtest.h"
#include "0010_regular_matching/regular_matching.h"
#include <iostream>
using namespace std;

int main()
{
    Solution su;
    cout << "re: " << su.isMatch("ab", ".*c")<< endl;
    cout << "re: " << su.isMatch("", "..*")<< endl;
    cout << "re: " << su.isMatch("a", ".*..a*")<< endl;
    cout << "re: " << su.isMatch("aaa", "ab*a")<< endl;
    cout << "re: " << su.isMatch("aaa", ".a")<< endl;
    cout << "re: " << su.isMatch("aa", ".*")<< endl;
    cout << "re: " << su.isMatch("aa", "a") << endl;
    cout << "re: " << su.isMatch("aa", "aa")<< endl;
    cout << "re: " << su.isMatch("aaa", "aa")<< endl;
    cout << "re: " << su.isMatch("aa", "a*")<< endl;
    cout << "re: " << su.isMatch("ab", ".*")<< endl;
    cout << "re: " << su.isMatch("aab", "c*a*b*")<< endl;
    return 0;
}
// aaa, ab*a
// aa, ab*
//
