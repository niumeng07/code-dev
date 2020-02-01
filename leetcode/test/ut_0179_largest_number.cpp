#include "0179_largest_number/largest_number.h"
#include "gtest/gtest.h"
#include <iostream>

int main(int argc, char **argv) {
  LargestNumber su;
  vector<int> input({3, 30, 34, 5, 9});
  string result = su.largestNumber(input);
  cout << result << endl;
  return 0;
}
