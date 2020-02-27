/**
 * @file n_queens.h
 * @brief
 * The n-queens puzzle is the problem of placing n queens on an n×n chessboard
 * such that no two queens attack each other.
 *
 * Given an integer n, return all distinct solutions to the n-queens puzzle.
 *
 * Each solution contains a distinct board configuration of the n-queens'
 * placement, where 'Q' and '.' both indicate a queen and an empty space
 * respectively.
 *
 * For example,
 * There exist two distinct solutions to the 4-queens puzzle:
 *
 * [
 *  [".Q..",  // Solution 1
 *   "...Q",
 *   "Q...",
 *   "..Q."],
 *
 *  ["..Q.",  // Solution 2
 *   "Q...",
 *   "...Q",
 *   ".Q.."]
 * ]
 * Subscribe to see which companies asked this question.
 *
 * //
 * Solution 1: 1, 3, 0, 2
 * Sulution 2: 2, 0, 3, 1
 *
 * @author myliuda@sina.com
 * @version 0.0.1
 * @date 2020-02-08
 */
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
bool isValid(vector<int> &t) {
  for (int i = 0; i < t.size(); i++)
    for (int j = i + 1; j < t.size(); j++)
      if (abs(i - j) == abs(t[i] - t[j]))
        return false;
  return true;
}
class NQueens {
public:
  vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> res;
    vector<int> t(n, 0);
    string s(n, '.');
    for (int i = 0; i < n; i++)
      t[i] = i;
    do {
      if (isValid(t)) {
        vector<string> v;
        for (int i = 0; i < t.size(); i++) {
          s[t[i]] = 'Q';
          v.push_back(s);
          s[t[i]] = '.';
        }
        res.push_back(std::move(v));
      }
    } while (std::next_permutation(t.begin(), t.end()));
    return res;
  }

  bool valid(vector<vector<string>> &input) {
    for (int i = 0; i < input.size(); i++) {
      bool hasQ = false;
      for (int j = 0; j < input[i].size(); j++) {
        if (input[i][j] == "Q" && !hasQ) {
          hasQ = true;
        } else if (input[i][j] == "Q" && hasQ) {
          return false;
        }
      }
    }
    return true;
  }
};
