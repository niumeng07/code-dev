#include "Solution.h"
#include <iostream>
using namespace std;

int main() {
  vector<int> B({1,2,3});
  uint32_t N = 1000000000;
  Solution *su = new Solution(N, B);
  //cout << su->pick() << endl;
  return 0;
}