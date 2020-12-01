#include <iostream>
#include <sstream>
#include <random>
#include <time.h>
#include <iomanip>      // std::setprecision

using namespace std;

void test() {
  std::stringstream ss;
  clock_t start, end;
  start = clock();
  for (int i = 1; i < 100; ++i) {
    ss << rand() % 100
       << rand() % 100
       << rand() % 100
       << rand() % 100
       << rand() % 100
       << rand() % 100
       << rand() % 100
       << rand() % 100
       << rand() % 100
       << rand() % 100;
  }
  end = clock();
  cout << end - start << endl;

  std::stringstream ss2;
  start = clock();
  for (int i = 1; i < 1000; ++i) {
    ss2 << rand() % 100;
  }
  end = clock();
  cout << end - start << endl;
}

void test2() {
  float x= 0.0000000123456;
  stringstream ss;
  ss << std::setprecision(20) << x;
  int y = 1;
  float z = 0.000111;
  ss << ";" << std::setprecision(1) << y << ";" << std::setprecision(20) << z;

  cout << ss.str() << endl;
}

void test3() {
  stringstream ss;
  double x = 1.3445687362478234;
  int y = 1;
  ss << setprecision(10) << x
    << ", " << y;
  cout << ss.str() << endl;
}

int main(int argc, char *argv[])
{
  // test2(); 
  test3();
  return 0;
}
