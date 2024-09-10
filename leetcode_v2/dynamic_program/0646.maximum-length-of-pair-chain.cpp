/* 给你一个由 n 个数对组成的数对数组 pairs ，其中 pairs[i] = [lefti, righti] 且 lefti < righti 。
 *
 * 现在，我们定义一种 跟随 关系，当且仅当 b < c 时，数对 p2 = [c, d] 才可以跟在 p1 = [a, b] 后面。我们用这种形式来构造
 * 数对链 。
 *
 * 找出并返回能够形成的 最长数对链的长度 。
 * 你不需要用到所有的数对，你可以以任何顺序选择其中的一些数对来构造。
 *
 * 示例 1：
 * 输入：pairs = [[1,2], [2,3], [3,4]]
 * 输出：2
 * 解释：最长的数对链是 [1,2] -> [3,4] 。
 *
 * 示例 2：
 * 输入：pairs = [[1,2],[7,8],[4,5]]
 * 输出：3
 * 解释：最长的数对链是 [1,2] -> [4,5] -> [7,8] 。
 *
 * 提示：
 * n == pairs.length
 * 1 <= n <= 1000
 * -1000 <= lefti < righti <= 1000
 * */

#include "header.h"

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int m = pairs.size();
        if (m <= 1) {
            return m;
        };

        sort(pairs.begin(), pairs.end());  // 需要保证先按left排序，left相等时按right排序

        vector<int> vec(m, 1);  // 1初始化

        int result = 1;
        for (int i = 1; i < m; i++) {  // [1,2],[7,8],[4,5]
            // i=1代表从pairs[0]到pairs[1]能组成的的结果
            for (int j = 0; j < i; j++) {
                if (pairs[i][0] > pairs[j][1]) {
                    vec[i] = max(vec[i], vec[j] + 1);
                } else {
                    vec[i] = max(vec[i], vec[j]);
                }
            }
            result = max(result, vec[i]);
        }
        return result;
    }
};

int main(int argc, char* argv[]) {
    vector<vector<int>> pairs = {{1, 2}, {2, 3}, {3, 4}};
    cout << Solution().findLongestChain(pairs) << " == 2" << endl;

    pairs = {{1, 2}, {7, 8}, {4, 5}};
    cout << Solution().findLongestChain(pairs) << " == 3" << endl;

    pairs = {{1, 2}, {7, 8}, {4, 8}};
    cout << Solution().findLongestChain(pairs) << " == 2" << endl;

    pairs = {{1, 5}, {1, 2}, {4, 8}};
    cout << Solution().findLongestChain(pairs) << " == 2" << endl;
    return 0;
}
