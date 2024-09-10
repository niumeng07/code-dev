/* 给你两个单词 word1 和 word2， 请返回将 word1 转换成 word2 所使用的最少操作数  。
 *
 * 你可以对一个单词进行如下三种操作：
 *
 * 插入一个字符
 * 删除一个字符
 * 替换一个字符
 *
 *
 * 示例 1：
 * 输入：word1 = "horse", word2 = "ros"
 * 输出：3
 *
 * 解释：
 * horse -> rorse (将 'h' 替换为 'r')
 * rorse -> rose (删除 'r')
 * rose -> ros (删除 'e')
 *
 *
 * 示例 2：
 * 输入：word1 = "intention", word2 = "execution"
 * 输出：5
 *
 * 解释：
 * intention -> inention (删除 't')
 * inention -> enention (将 'i' 替换为 'e')
 * enention -> exention (将 'n' 替换为 'x')
 * exention -> exection (将 'n' 替换为 'c')
 * exection -> execution (插入 'u')
 *
 *
 * 提示：
 * 0 <= word1.length, word2.length <= 500
 * word1 和 word2 由小写英文字母组成
 * */

#include "header.h"

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        if (m == 0) {
            return n;
        }
        if (n == 0) {
            return m;
        }
        vector<vector<int>> matrix(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i <= m; i++) {
            matrix[i][0] = i;  // word1的前i个字符和空
        }
        for (int j = 0; j <= n; j++) {
            matrix[0][j] = j;  // word2的前j个字符和空
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (word1[i] == word2[j]) {
                    matrix[i + 1][j + 1] = matrix[i][j];  // 这里注意：不再是min (left, up, upleft)
                } else {
                    matrix[i + 1][j + 1] = min(matrix[i][j], min(matrix[i][j + 1], matrix[i + 1][j])) + 1;  // 替换
                }
            }
        }
        // print_matrix(matrix);
        return matrix[m][n];
    }
};

int main(int argc, char *argv[]) {
    cout << Solution().minDistance("zoogeo", "zoologieo") << "  标准答案是: " << 3 << endl;
    cout << Solution().minDistance("ab", "bc") << "  标准答案是: " << 2 << endl;
    cout << Solution().minDistance("intention", "execution") << "  标准答案是: " << 5 << endl;
    cout << Solution().minDistance("horse", "ros") << "  标准答案是: " << 3 << endl;
    cout << Solution().minDistance("", "exe") << "  标准答案是: " << 3 << endl;
    cout << Solution().minDistance("", "") << "  标准答案是: " << 0 << endl;
    cout << Solution().minDistance("exe", "exe") << "  标准答案是: " << 0 << endl;
    return 0;
}
/*
    z o o   l o   g i e o
  0 1 2 3   4 5   6 7 8 9
z 1 0 1 2   3 4   5 6 7 8
o 2 1 0 0   1 1   2 3 4 4
o 3 2 0 0   1 1   2 3 4 4

g 4 3 1 1   1 2   1 2 3 4
e 5 4 2 2   2 2   2 2 2 3

o 6 5 2 2   3 2   3 3 3 2
*/
