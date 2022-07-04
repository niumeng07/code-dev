#include <math.h>
#include <iostream>
using namespace std;

void test1() {
  int r1 = 1;
  int r2 = 10;
  if (abs(static_cast<double>(r1-r2)/r2) > 0.2) {
    cout << 1 << endl;
  }
}

int main(int argc, char *argv[])
{
  test1();
  return 0;
}
