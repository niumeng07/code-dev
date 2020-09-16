#include <iostream>
#include <sstream>
#include <random>
#include <time.h>

using namespace std;

int main(int argc, char *argv[])
{
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
  return 0;
}
