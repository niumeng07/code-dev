#include "Solution.h"
#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> input({1, 2, 0, 3, 4, 0, 0, 5, 6, 7, 0, 0, 0});
  vector<int> input2({});
  vector<int> input3({0});
  vector<int> input4({0, 4});
  vector<int> input5({4});
  // Solution su;
  Solution().moveZeroes(input);
  Solution().moveZeroes(input2);
  Solution().moveZeroes(input3);
  Solution().moveZeroes(input4);
  Solution().moveZeroes(input5);
  printVector(input);
  printVector(input2);
  printVector(input3);
  printVector(input4);
  printVector(input5);
}
