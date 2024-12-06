#include "header.h"

class Solution {
public:
    int max_size = 0;
    int curr_size = 0;
    int rows = 0;
    int cols = 0;

    void DFS(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& matrix) {
        if (matrix[i][j] > 0) {
            return;  // 当前点被访问过
        }

        matrix[i][j] = 1;  // 标记为已访问

        if (grid[i][j] > 0) {  // 当前点不是0
            curr_size++;
        } else {  // 当前点是0
            max_size = max(max_size, curr_size);
            curr_size = 0;
            return;
        }
        if (i + 1 < rows && grid[i + 1][j] > 0) DFS(grid, i + 1, j, matrix);
        if (j + 1 < cols && grid[i][j + 1] > 0) DFS(grid, i, j + 1, matrix);
        if (i - 1 >= 0 && grid[i - 1][j] > 0) DFS(grid, i - 1, j, matrix);
        if (j - 1 >= 0 && grid[i][j - 1] > 0) DFS(grid, i, j - 1, matrix);
        max_size = max(max_size, curr_size);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        rows = grid.size();
        if (rows == 0) {
            return 0;
        }
        cols = grid[0].size();
        if (cols == 0) {
            return 0;
        }
        vector<vector<int>> matrix(rows, vector<int>(cols, 0));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == 0) {
                    curr_size = 0;            // 从每个点进行时要重置curr_size
                    DFS(grid, i, j, matrix);  // 循环是为了防止孤点,matrix记录已经访问过的点用于加速
                }
            }
        }
        return max_size;
    }
};

int main(int argc, char* argv[]) {
    vector<vector<int>> grid = {
            {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
            {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
            {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0},
    };
    cout << Solution().maxAreaOfIsland(grid) << endl;

    grid = {
            {0, 0},
    };
    cout << Solution().maxAreaOfIsland(grid) << endl;

    grid = {};
    cout << Solution().maxAreaOfIsland(grid) << endl;

    grid = {
            {0, 1},
    };
    cout << Solution().maxAreaOfIsland(grid) << endl;

    grid = {
            {1, 1},
            {1, 0},
    };
    cout << Solution().maxAreaOfIsland(grid) << endl;

    grid = {
            {1, 1, 0, 1, 1},
            {1, 0, 0, 0, 0},
            {0, 0, 0, 0, 1},
            {1, 1, 0, 1, 1},
    };
    cout << Solution().maxAreaOfIsland(grid) << endl;
    return 0;
}
