#include "0051_n_queens/n_queens.h"
#include "gtest/gtest.h"
#include <iostream>
#include <time.h>
#include <vector>
using namespace std;
TEST(n_queens, test0) {
  clock_t start, end;
  start = clock();
  vector<vector<string>> res = NQueens().solveNQueens(6);
  end = clock();
  std::cout << "Time used: " << end - start << std::endl;
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
