/**
 * @brief
 * Given a string S and a string T, count the number of distinct subsequences of
 * S which equals T.
 *
 * A subsequence of a string is a new string which is formed from the original
 * string by deleting some (can be none) of the characters without disturbing
 * the relative positions of the remaining characters. (ie, "ACE" is a
 * subsequence of "ABCDE" while "AEC" is not).
 *
 * Here is an example:
 * S = "rabbbit", T = "rabbit"
 *
 * Return 3.
 *
 * matrix dp with S.size( named m) rows, T.size( named n) columns
 *
 * dp[0][0]=1 dp[0][1] ... dp[0][n-1]
 * dp[1][0] ...
 * dp[2][0] ...
 * ...
 * dp[m-1][0] dp[m-1][1] ... dp[m-1][n-1]
 *
 * f(0,0)=1 f(0,1)=0          f(0,2)=0                ...
 * f(1,0)=1 f(1,1)=(s==t)?1:0 f(1,2)=0                ...
 * f(2,0)=1 f(2,1)=2:1:0      f(2,2)=(s==t)?1:0
 * f(3,0)=1 f(3,1)=3:2:1:0    f(3,2)                 f(3,3)=1:0  ....
 */
#include <iostream>
#include <string>
using namespace std;

class DistinctSubSequence {
public:
    int numDistinct(string s, string t) {
        if (t.size() > s.size()) return 0;
        if (t.size() == s.size()) return 1;
        int i = 0, j = 0;
        return 0;
    }
};
