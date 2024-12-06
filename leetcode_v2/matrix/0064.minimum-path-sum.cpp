/*
给定一个包含非负整数的 m x n 网格 grid ，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。

说明：每次只能向下或者向右移动一步。

示例 1：
输入：grid = [[1,3,1],[1,5,1],[4,2,1]]
输出：7
解释：因为路径 1→3→1→1→1 的总和最小。

示例 2：
输入：grid = [[1,2,3],[4,5,6]]
输出：12
*/

#include "header.h"

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();
        if (n == 0) return 0;

        vector<vector<int>> matrix(m, vector<int>(n, 0));
        matrix[0][0] = grid[0][0];

        for (int i = 1; i < m; i++) {  // m是行数
            matrix[i][0] = matrix[i - 1][0] + grid[i][0];
        }
        for (int j = 1; j < n; j++) {
            matrix[0][j] = matrix[0][j - 1] + grid[0][j];
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                matrix[i][j] = grid[i][j] + min(matrix[i - 1][j], matrix[i][j - 1]);
            }
        }
        return matrix[m - 1][n - 1];
    }
};

int main(int argc, char* argv[]) {
    vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    cout << Solution().minPathSum(grid) << endl;
    grid = {{1, 2, 3}, {4, 5, 6}};
    cout << Solution().minPathSum(grid) << endl;
    return 0;
}
