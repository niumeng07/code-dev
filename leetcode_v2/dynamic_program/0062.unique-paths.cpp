#include "header.h"

/*
 * 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。
 * 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。
 * 问总共有多少条不同的路径？
 * */
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> grid(m, vector<int>(n, 0));  // m行
        for (int i = 0; i < n; i++) {
            grid[0][i] = 1;  // 第0行的每个元素
        }
        for (int i = 0; i < m; i++) {
            grid[i][0] = 1;  // 第0列的每个元素
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                grid[i][j] = grid[i - 1][j] + grid[i][j - 1];
            }
        }

        /*
        for (const auto& v: grid) {
            print_vector(v);
        }*/
        return grid[m - 1][n - 1];
    }
};

int main(int argc, char* argv[]) {
    cout << Solution().uniquePaths(3, 7) << endl;
    cout << Solution().uniquePaths(3, 2) << endl;
    cout << Solution().uniquePaths(7, 3) << endl;
    cout << Solution().uniquePaths(3, 3) << endl;
    return 0;
}
