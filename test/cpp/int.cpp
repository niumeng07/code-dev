#include <iostream>
#include <limits>
using namespace std;

void test1() { cout << std::numeric_limits<int>::max() << endl; }
void test2() {
  long a = 1636117944430;
  uint64_t b = a / 60;
  long c = a / 60;
  cout << b << ", " << c << endl;
}
int main(int argc, char *argv[]) {
  test2();
  return 0;
}
