#include <iostream>
#include <wchar.h>
#include <vector>
using namespace std;
class Solution {
public:
  int numIslands(vector<vector<char> > &grid) {
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[i].size(); j++) {
        int left = i - 1 >= 0 ? grid[i - 1][j] : 0;
        int right = i + 1 < grid.size() ? grid[i + 1][j] : 0;
        int up = j - 1 >= 0 ? grid[i][j - 1] : 0;
        int down = j + 1 < grid[i].size() ? grid[i][j + 1] : 0;
        if (grid[i][j] == '1' &&
            (left == '1' || right == '1' || up == '1' || down == '1')) {
          grid[i][j] = '0';
        }
      }
    }
    int num = 0;
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[i].size(); j++) {
        if (grid[i][j] == '1')
          num += 1;
      }
    }
    return num;
  }
};
