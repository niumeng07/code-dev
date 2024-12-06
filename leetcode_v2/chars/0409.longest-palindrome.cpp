#include "header.h"

/* 给定一个包含大写字母和小写字母的字符串 s ，返回 通过这些字母构造成的 最长的
 * 回文串的长度。
 *
 * 在构造过程中，请注意 区分大小写 。比如 "Aa" 不能当做一个回文字符串。
 *
 * 示例 1:
 * 输入:s = "abccccdd"
 * 输出:7
 * 解释:
 * 我们可以构造的最长的回文串是"dccaccd", 它的长度是 7。
 *
 * 示例 2:
 * 输入:s = "a"
 * 输出:1
 * 解释：可以构造的最长回文串是"a"，它的长度是 1。
 * */

// 发现原题的题义根本不是这么麻烦，简单的两个字母的都要，单个字母的最多存在一个
class Solution {
public:
    int longestPalindrome(string s) {
        if (s.size() <= 1) {
            return s.size();
        }
        int m = s.size();

        // 用于保存从i->j的位置的字符串的回文串长度（如不是回文串，存0）
        vector<vector<int>> matrix(m, vector<int>(m, 0));

        int index = 3;
        for (int i = 0; i < m; i++) {
            matrix[i][i] = 1;
        }
        for (int k = 1; k < m; k++) {
            // 斜线遍历，对角线已经给过值了，需要遍历m-1次
            for (int i = 0; i + k < m; i++) {
                // 第k轮遍历
                // 第1轮 0,1->1,2->2,3
                // 第2轮 0,2->1,3->2,4  // 第一个数是i，第二个数是i+k
                if (k == 1) {
                    matrix[i][i + k] = int(s[i] == s[i + k]);
                } else {
                    matrix[i][i + k] = int(matrix[i + 1][i + k - 1] && (s[i] == s[i + k]));
                }
            }
        }
        int result = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                result = max(result, (matrix[i][j] > 0) ? j - i + 1 : 0);
            }
        }

        return result;
    }
};

int main(int argc, char *argv[]) {
    cout << Solution().longestPalindrome("abccccdd") << endl;
    // cout << Solution().longestPalindrome("dccaccd") << endl;
    // cout << Solution().longestPalindrome("a") << endl;
    return 0;
}
