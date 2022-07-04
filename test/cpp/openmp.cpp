#include <omp.h>
#include <time.h>

#include <iostream>
using namespace std;

int main() {
  clock_t start = clock();
#pragma omp parallel for
  for (int i = 0; i < 100; ++i) {
    std::cout << i;
  }
  cout << endl;
  clock_t end = clock();
  cout << end - start << endl;

  start = clock();
  for (int i = 0; i < 100; ++i) {
    std::cout << i;
  }
  end = clock();
  cout << endl;

  cout << end - start << endl;

  return 0;
}
