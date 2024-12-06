#include "header.h"
/*
给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。

岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。

此外，你可以假设该网格的四条边均被水包围。



示例 1：

输入：grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
输出：1
示例 2：

输入：grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
输出：3
*/

class Solution {
public:
    int result = 0;
    int rows = 0;
    int cols = 0;

    bool new_island = true;

    void DFS(int i, int j, vector<vector<char>>& grid, vector<vector<int>>& visited) {
        // cout << "i=" << i << ", j=" << j << ", grid[i][j]=" << grid[i][j] << ", visited[i][j]=" << visited[i][j] << ", new_island:" << new_island << endl;
        if (i >= rows || j >= cols || visited[i][j] > 0) {
            return;
        }

        visited[i][j] = 1;

        if (grid[i][j] == '1' && new_island) {
            result++;
        }

        if (grid[i][j] == '1') new_island = false;
        else new_island = true;

        if (i + 1 < rows && visited[i + 1][j] == 0) DFS(i + 1, j, grid, visited);
        if (j + 1 < cols && visited[i][j + 1] == 0) DFS(i, j + 1, grid, visited);
        if (i - 1 > 0 && visited[i - 1][j] == 0) DFS(i - 1, j, grid, visited);
        if (j - 1 > 0 && visited[i][j - 1] == 0) DFS(i, j - 1, grid, visited);
    }

    int numIslands(vector<vector<char>>& grid) {
        rows = grid.size();
        if (rows == 0) return result;
        cols = grid[0].size();
        if (cols == 0) return result;

        vector<vector<int>> visited(rows, vector<int>(cols, 0));

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (visited[i][j] == 0 && grid[i][j] == '1') {
                    DFS(i, j, grid, visited);
                }
            }
        }

        return result;
    }
};

int main(int argc, char* argv[]) {
    vector<vector<char>> grid = {
            {'1', '1', '1', '1', '0'},
            {'1', '1', '0', '1', '0'},
            {'1', '1', '0', '0', '0'},
            {'0', '0', '0', '0', '0'},
    };
    // cout << Solution().numIslands(grid) << "==? 1" << endl;

    grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}};
    cout << Solution().numIslands(grid) << "==? 3" << endl;
    return 0;
}
