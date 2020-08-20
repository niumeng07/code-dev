#include "0703_kth_largest_element_in_a_stream/kth_largest_element_in_a_stream.h"
#include "gtest/gtest.h"
#include <string>
#include <vector>

using namespace std;
void test0() {
  vector<int> input({1, 2, 5, 3});
  KthLargest *large = new KthLargest(3, input);
  std::cout << large->add(10) << std::endl;
}

int main(int argc, char **argv) {
  test0();
  return 0;
}
