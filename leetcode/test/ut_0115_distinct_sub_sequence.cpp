#include "0115_distinct_sub_sequence/distinct_sub_sequence.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char **argv) {
  string S = "rabbbit";
  string T = "rabbit";
  DistinctSubSequence su;
  cout << su.numDistinct(S, T) << endl;
}
