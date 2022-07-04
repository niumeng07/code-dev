#include <iostream>
#include <string>
#include <time.h>
#include <random>

using namespace std;

string cross(uint64_t x, uint64_t y) {
  uint64_t tmp[2];
  tmp[0] = x;
  tmp[1] = y;
  return std::string((const char*)&tmp[0]);
}
int main(int argc, char *argv[])
{
  clock_t start, end;
  uint64_t x = 0, y = 0; 
  start = clock();
  for (int i = 1; i < 10000; i++) {
    x = rand();
    y = rand();
    string z = to_string(x) + to_string(y);
  }
  end = clock();
  cout << end - start << endl;

  start = clock();
  for (int i = 1; i < 10000; i++) {
    x = rand();
    y = rand();
    string z = cross(x, y);
  }
  end = clock();
  cout << end - start << endl;

  return 0;
}
