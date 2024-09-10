/*
 * 给定两个字符串 text1 和 text2，返回这两个字符串的最长 公共子序列 的长度。如果不存在 公共子序列 ，返回 0 。
 * 一个字符串的 子序列
 * 是指这样一个新的字符串：它是由原字符串在不改变字符的相对顺序的情况下删除某些字符（也可以不删除任何字符）后组成的新字符串。
 *
 * 例如，"ace" 是 "abcde" 的子序列，但 "aec" 不是 "abcde" 的子序列。
 * 两个字符串的 公共子序列 是这两个字符串所共同拥有的子序列。
 *
 * 示例 1：
 * 输入：text1 = "abcde", text2 = "ace"
 * 输出：3
 * 解释：最长公共子序列是 "ace" ，它的长度为 3 。
 *
 * 示例 2：
 * 输入：text1 = "abc", text2 = "abc"
 * 输出：3
 * 解释：最长公共子序列是 "abc" ，它的长度为 3 。
 *
 * 示例 3：
 * 输入：text1 = "abc", text2 = "def"
 * 输出：0
 * 解释：两个字符串没有公共子序列，返回 0 。
 * */

#include "header.h"

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        if (m == 0 || n == 0) {
            return 0;
        }
        vector<vector<int>> grid(m + 1, vector<int>(n + 1, 0));  // 由text1的前i位和text2的前j位能得到的最长子序列
        /* // 初始化，省略
         * grid[0][0] = 0;
         * for (int i = 0; i < m; i++) {
         *     grid[i][0] = 0;
         * }
         * for (int j = 0; j < n; j++) {
         *     grid[0][j] = 0;
         * }
         * */

        for (int i = 0; i < m; i++) {        // 从text1的第0个字符开始
            for (int j = 0; j < n; j++) {    // 从text2的第0个字符开始
                if (text1[i] == text2[j]) {  // 如果这两个字符相等,注意：结果放在grid[i + 1][j + 1]
                    grid[i + 1][j + 1] = max(grid[i][j] + 1, max(grid[i][j + 1], grid[i + 1][j]));
                } else {  // 如果当前字符不相等
                    grid[i + 1][j + 1] = max(grid[i][j + 1], grid[i + 1][j]);
                }
            }
        }
        return grid[m][n];
    }
};

int main(int argc, char *argv[]) {
    cout << Solution().longestCommonSubsequence("ace", "abcde") << endl;
    cout << Solution().longestCommonSubsequence("abc", "abc") << endl;
    cout << Solution().longestCommonSubsequence("abc", "def") << endl;

    return 0;
}
