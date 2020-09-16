#include <iostream>
#include <vector>
using namespace std;

/*
 * Write an efficient algorithm that searches for a value in an m x n matrix.
 * This matrix has the following properties:
 * Integers in each row are sorted in ascending from left to right.
 * Integers in each column are sorted in ascending from top to bottom.
 * Example:
 *
 * Consider the following matrix:
 *
 * [
 *   [1,   4,  7, 11, 15],
 *   [2,   5,  8, 12, 19],
 *   [3,   6,  9, 16, 22],
 *   [10, 13, 14, 17, 24],
 *   [18, 21, 23, 26, 30]
 * ]
 * Given target = 5, return true.
 * Given target = 20, return false.
 * */
class Solution {
private:
    bool search(vector<vector<int> >& matrix, int target, int row_start,
                int row_end, int column_start, int column_end) {
        if (matrix[row_start][column_start] > target) {
            return false;
        }
        if (matrix[row_end][column_end] < target) {
            return false;
        }

        if (row_start + 1 >= row_end && column_start + 1 >= column_end) {
            if (matrix[row_start][column_start] == target ||
                matrix[row_start][column_end] == target ||
                matrix[row_end][column_start] == target ||
                matrix[row_end][column_end] == target) {
                return true;
            } else {
                return false;
            }
        }

        int row_middle = (row_start + row_end) / 2;
        int column_middle = (column_start + column_end) / 2;

        if (matrix[row_middle][column_middle] > target) {
            return search(matrix, target, row_start, row_middle, column_start,
                          column_middle) ||
                   search(matrix, target, row_start, row_middle, column_middle,
                          column_end) ||
                   search(matrix, target, row_middle, row_end, column_start,
                          column_middle);
        } else {
            return search(matrix, target, row_start, row_middle, column_middle,
                          column_end) ||
                   search(matrix, target, row_middle, row_end, column_start,
                          column_middle) ||
                   search(matrix, target, row_middle, row_end, column_middle,
                          column_end);
        }
    }

public:
    // 评价: 此方法用最通用的二分查找AC,实际上并没有分析矩阵固有的特性
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        int m = matrix.size();
        if (m == 0) return false;
        int n = matrix[0].size();
        if (n == 0) return false;

        return search(matrix, target, 0, m - 1, 0, n - 1);
    }

    // 利用了给定的矩阵特性
    bool searchMatrixMN(vector<vector<int> >& matrix, int target) {
        int m = matrix.size();
        if (m == 0) return false;
        int n = matrix[0].size();
        if (n == 0) return false;
        
        m--;
        n = 0;
        while (m >= 0 && n < matrix[0].size()) {
            if (matrix[m][n] == target) return true;
            else if (matrix[m][n] > target)
                m--;
            else
                n++;
        }
        return false;

    }
};
