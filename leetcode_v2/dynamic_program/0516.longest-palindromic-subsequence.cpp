/*
给你一个字符串 s ，找出其中最长的回文子序列，并返回该序列的长度。

子序列定义为：不改变剩余字符顺序的情况下，删除某些字符或者不删除任何字符形成的一个序列。

示例 1：
输入：s = "bbbab"
输出：4
解释：一个可能的最长回文子序列为 "bbbb" 。

示例 2：
输入：s = "cbbd"
输出：2
解释：一个可能的最长回文子序列为 "bb" 。
*/
#include "header.h"

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int m = s.size();
        if (m <= 1) {
            return m;
        }
        string sr = s;
        std::reverse(sr.begin(), sr.end());

        vector<vector<int>> matrix(m + 1, vector<int>(m + 1, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                if (s[i] == sr[j]) {
                    matrix[i + 1][j + 1] = matrix[i][j] + 1;
                } else {
                    matrix[i + 1][j + 1] = max(matrix[i + 1][j], matrix[i][j + 1]);
                }
            }
        }

        // print_matrix(matrix);

        return matrix[m][m];
    }
};
int main(int argc, char *argv[]) {
    cout << Solution().longestPalindromeSubseq("bbbab") << " 标准答案: " << 4 << endl;
    cout << Solution().longestPalindromeSubseq("cbbd") << " 标准答案: " << 2 << endl;
    return 0;
}
