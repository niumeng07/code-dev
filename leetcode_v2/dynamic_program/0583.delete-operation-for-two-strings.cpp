/*
给定两个单词 word1 和 word2 ，返回使得 word1 和  word2 相同所需的最小步数。

每步 可以删除任意一个字符串中的一个字符。

示例 1：
输入: word1 = "sea", word2 = "eat"
输出: 2
解释: 第一步将 "sea" 变为 "ea" ，第二步将 "eat "变为 "ea"

示例  2:
输入：word1 = "leetcode", word2 = "etco"
输出：4

提示：

1 <= word1.length, word2.length <= 500
word1 和 word2 只包含小写英文字母
*/
#include "header.h"

// 该题只可以删除，和可以增删改的编辑距离(0072.edit-distance.cpp)类似
// 区别：如果只有一个字符的区别，本题需要删除两次，0072只需要修改一次
// 所以: 实现上和0072不同之处在于，如果当前字符不同，从up-left变来要两步(0072只需要一步),
// 左left或up变来只要一步(0072也仅需一步)
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        if (m == 0 && n == 0) {
            return 0;
        }
        if (word1 == word2) {
            return 0;
        }
        vector<vector<int>> matrix(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i <= m; i++) {
            matrix[i][0] = i;
        }
        for (int j = 0; j <= n; j++) {
            matrix[0][j] = j;
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (word1[i] == word2[j]) {
                    matrix[i+1][j+1] = matrix[i][j];
                } else {  // word1 word2都要删除该字符
                    matrix[i + 1][j + 1] = min(matrix[i][j] + 2, min(matrix[i + 1][j], matrix[i][j + 1]) + 1);
                }
            }
        }
        return matrix[m][n];
    }
};

int main(int argc, char *argv[]) {
    cout << Solution().minDistance("sea", "eat") << " 标准答案: " << 2 << endl;
    cout << Solution().minDistance("leetcode", "etco") << " 标准答案: " << 4 << endl;
    cout << Solution().minDistance("a", "b") << " 标准答案: " << 2 << endl;
    return 0;
}
