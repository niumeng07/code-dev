#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

std::vector<int> x;
int main(int argc, char *argv[])
{
  x.reserve(100);
  clock_t start = clock();
  for (int i = 0; i < 10000; i++) {
    x.push_back(i);
    if (i % 100 == 0)  {
      x.erase(x.begin(), x.end());
    }
  }
  clock_t end = clock();
  std::cout << end - start << std::endl;

  std::vector<int> y;
  y.reserve(100);
  start = clock();
  for (int i = 0; i < 10000; i++) {
    y.push_back(i);
    if (i % 100 == 0)  {
      y.erase(y.begin(), y.end());
    }
  }
  end = clock();
  std::cout << end - start << std::endl;

  return 0;
}
