/**
 * @file main.cpp
 * @brief
 * @author myliuda@sina.com
 * @version 0.0
 * @date 2020-01-28
 */

#include "Solution.h"
#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> v({1, 2, 3, 4, 1, 2, 3});
  // std::cout << Solution().findSingleNum(v) << std::endl;
  v = {13, 46, 8,  11, 20, 17, 40, 13, 13, 13, 14, 1,  13, 36, 48, 41, 13,
       13, 13, 13, 45, 13, 28, 42, 13, 10, 15, 22, 13, 13, 13, 13, 23, 9,
       6,  13, 47, 49, 16, 13, 13, 39, 35, 13, 32, 29, 13, 25, 30, 13};
  std::cout << Solution().findDuplicate2(v) << std::endl;
  return 0;
}
