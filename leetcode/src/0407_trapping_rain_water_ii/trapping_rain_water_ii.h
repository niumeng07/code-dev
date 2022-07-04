#include <iostream>
#include <queue>
using namespace std;

/*
 * Given an m x n integer matrix heightMap representing the height of each unit
 * cell in a 2D elevation map, return the volume of water it can trap after
 * raining.
 *
 * Example 1:
 * Input: heightMap = [[1,4,3,1,3,2],[3,2,1,3,2,4],[2,3,3,2,3,1]]
 * Output: 4
 *
 * Explanation: After the rain, water is trapped between the blocks.
 * We have two small ponds 1 and 3 units trapped.
 * The total volume of water trapped is 4.
 *
 * Example 2:
 * Input: heightMap =
 * [[3,3,3,3,3],[3,2,2,2,3],[3,2,1,2,3],[3,2,2,2,3],[3,3,3,3,3]] Output: 10
 *
 * Constraints:
 * m == heightMap.length
 * n == heightMap[i].length
 * 1 <= m, n <= 200
 * 0 <= heightMap[i][j] <= 2 * 104
 * */

class Cell {
public:
    int x_;
    int y_;
    int height_;
    Cell(int i, int j, int height) {
        x_ = i;
        y_ = j;
        height_ = height;
    }
};

// 最大堆转最小堆
bool operator<(const Cell& u1, const Cell& u2) {
    return u1.height_ > u2.height_;
}

class Solution {
public:
    int trapRainWater(vector<vector<int>> arr) {
        if (arr.size() <= 2) return 0;
        if (arr[0].size() <= 2) return 0;

        priority_queue<Cell> pq;
        int n = arr.size();
        int m = arr[0].size();
        vector<vector<int>> visited(n, vector<int>(m, false));

        // 用边界建立最小堆,乘水量由最矮的位置确定
        for (int i = 0; i < n; i++) {
            pq.push(Cell(i, 0, arr[i][0]));
            visited[i][0] = true;

            pq.push(Cell(i, m-1, arr[i][m-1]));
            visited[i][m-1] = true;
        }

        for (int j = 0; j < m; j++) {
            pq.push(Cell(0, j, arr[0][j]));
            visited[0][j] = true;

            pq.push(Cell(n-1, j, arr[n-1][j]));
            visited[n-1][j] = true;
        }

        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int water = 0;

        while (!pq.empty()) {
            Cell removed = pq.top();  // 在边缘上最矮的位置,只有比这里更矮的相信位置才能接水
            pq.pop();

            for (vector<int>& dir : directions) {
                int newRow = removed.x_ + dir[0];
                int newCol = removed.y_ + dir[1];

                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m &&
                    visited[newRow][newCol] == false) {
                    visited[newRow][newCol] = true;

                    if (arr[newRow][newCol] >= removed.height_) {   // 相邻位置高于或等于位置位置,不能乘水,形成新的边界
                        pq.push(Cell(newRow, newCol, arr[newRow][newCol]));
                    } else {  // 相邻位置更矮,能接水,仍然用当前边界
                        pq.push(Cell(newRow, newCol, removed.height_));
                        water += removed.height_ - arr[newRow][newCol];
                    }
                } /*else {
                    // 如果当前位置已经访问过,则不需要再次计算
                }*/
            }
        }
        return water;
    }

    // 该方法不对,因为流水会转弯,不止要考虑上下左右的最低边缘
    int trapRainWaterError(vector<vector<int>>& heightMap) {
        size_t height = heightMap.size();
        if (height <= 2) return 0;
        size_t width = heightMap[0].size();
        if (width <= 2) return 0;
        vector<int> temp(width, 0);
        vector<vector<int>> max_hills;
        max_hills.reserve(height);
        for (size_t i = 0; i < height; i++) {
            max_hills.emplace_back(temp);
        }
        // 左右
        for (int i = 1; i < height - 1; i++) {
            int max_value = heightMap[i][0];
            for (int j = 1; j < width - 1; j++) {
                max_hills[i][j] = max_value;
                max_value = max(max_value, heightMap[i][j]);
            }
            max_value = heightMap[i][width - 1];
            for (int j = width - 2; j > 0; j--) {
                max_hills[i][j] = min(max_value, max_hills[i][j]);
                max_value = max(max_value, heightMap[i][j]);
            }
        }
        // 上下
        for (int j = 1; j < width - 1; j++) {
            int max_value = heightMap[0][j];
            for (int i = 1; i < height - 1; i++) {
                max_hills[i][j] = min(max_value, max_hills[i][j]);
                max_value = max(max_value, heightMap[i][j]);
            }
            max_value = heightMap[height - 1][j];
            for (int i = height - 2; i > 0; i--) {
                max_hills[i][j] = min(max_value, max_hills[i][j]);
                max_value = max(max_value, heightMap[i][j]);
            }
        }
        int sum = 0;
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (heightMap[i][j] < max_hills[i][j]) {
                    sum += (max_hills[i][j] - heightMap[i][j]);
                }
            }
        }
        return sum;
    }
};
