#include <iostream>
#include <math.h>

using namespace std;

static float LogTransformation(float originValue) {
  float value = originValue >= 1.0 ? log(originValue) : 0.0;
  return value;
}

void test1() {
  cout << LogTransformation(2.718) << endl;
  cout << LogTransformation(1/2.718) << endl;

  float x = 2.718;
  cout << x << ", " << log(x) << endl;
  x = 1/2.718;
  cout << x << ", " << log(x) << endl;
  x = 10;
  cout << x << ", " << log(x) << endl;
}

int main(int argc, char *argv[])
{
  test1();
  return 0;
}
