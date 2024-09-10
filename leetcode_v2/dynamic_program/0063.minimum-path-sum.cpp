#include "header.h"

/*
 * 给定一个包含非负整数的 m x n 网格 grid ，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
 * 说明：每次只能向下或者向右移动一步。
 *
 * 示例1
 * 输入：grid = [[1,3,1],[1,5,1],[4,2,1]]
 * 输出：7
 * 解释：因为路径 1→3→1→1→1 的总和最小。
 *
 * 示例 2：
 * 输入：grid = [[1,2,3],[4,5,6]]
 * 输出：12
 * */
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();  // 行数
        if (m == 0) {
            return 0;
        }
        int n = grid[0].size();  // 列数
        if (n == 0) {
            return 0;
        }

        for (int i = 1; i < n; i++) {  // dp[0]是第0行,对每一列给值
            grid[0][i] = grid[0][i - 1] + grid[0][i];
        }
        for (int j = 1; j < m; j++) {
            grid[j][0] = grid[j - 1][0] + grid[j][0];
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                grid[i][j] = min(grid[i - 1][j], grid[i][j - 1]) + grid[i][j];
            }
        }

        return grid[m - 1][n - 1];
    }
};

int main(int argc, char* argv[]) {
    vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    cout << Solution().minPathSum(grid) << endl;

    grid = {{1, 2, 3}, {4, 5, 6}};
    cout << Solution().minPathSum(grid) << endl;

    grid = {{1, 2}, {4, 5}, {3, 3}};
    cout << Solution().minPathSum(grid) << endl;
    return 0;
}
