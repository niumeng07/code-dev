#include "gtest/gtest.h"
#include "0200_numberof_islands/numberof_islands.h"
#include <iostream>
#include <vector>
using namespace std;

int main() {
  Solution su;
  vector<vector<char> > X = {{'1', '1', '1', '1', '0'},
                            {'1', '1', '0', '1', '0'},
                            {'1', '1', '0', '0', '0'},
                            {'0', '0', '0', '0', '0'}};
  cout << su.numIslands(X) << endl;
  return 0;
}
