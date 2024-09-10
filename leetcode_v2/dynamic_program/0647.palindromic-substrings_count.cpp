/* 给你一个字符串 s ，请你统计并返回这个字符串中 回文子串 的数目。
 * 回文字符串 是正着读和倒过来读一样的字符串。
 * 子字符串 是字符串中的由连续字符组成的一个序列。
 *
 * 示例 1：
 * 输入：s = "abc"
 * 输出：3
 * 解释：三个回文子串: "a", "b", "c"
 *
 * 示例 2：
 * 输入：s = "aaa"
 * 输出：6
 * 解释：6个回文子串: "a", "a", "a", "aa", "aa", "aaa"
 *
 * 提示：
 * 1 <= s.length <= 1000
 * s 由小写英文字母组成
 * */
#include "header.h"

class Solution {
public:
    int countSubstrings(string s) {
        int m = s.size();
        if (m <= 1) {
            return m;
        }
        // 从第i个字符到第j个字符是回否是回文串
        // matrix[i][j] = 1     <== matrix[i+1][j-1] == 1 and s[i] == s[j]
        // matrix[0][j+1] = 1   <== matrix[0][j] == 1 and s[0] == s[j+1]
        // 只需要上三角
        vector<vector<int>> matrix(m, vector<int>(m, 0));
        for (int i = 0; i < m; i++) {
            matrix[i][i] = 1;  // 只有一个字符的string一定是回文串
        }

        for (int i = 1; i < m; i++) {          // m次循环  -> N
            for (int k = 0; k + i < m; k++) {  // 内层是m-1, 平均是log(N)
                int x = k;
                int y = i + k;
                int y_ = x;
                if (matrix[x + 1][y - 1] == 1 && s[y] == s[y_]) {
                    matrix[x][y] = 1;
                } else if (x + 1 == y && matrix[x][y - 1] == 1 && s[y] == s[y - 1]) {
                    matrix[x][y] = 1;
                }
            }
        }
        int result = 0;
        for (int i = 0; i < m; i++) {
            result += std::accumulate(matrix[i].begin(), matrix[i].end(), 0);
        }

        return result;
    }
};

int main(int argc, char *argv[]) {
    cout << Solution().countSubstrings("wgww") << " 标准答案是 6" << endl;
    cout << Solution().countSubstrings("abc") << " 标准答案是 3" << endl;
    cout << Solution().countSubstrings("aaa") << " 标准答案是 6" << endl;
    return 0;
}
