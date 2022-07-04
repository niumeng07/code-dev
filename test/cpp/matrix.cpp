#include <iostream>
#include <vector>
#include <time.h>
#include <limits.h>

using namespace std;

int main(int argc, char *argv[])
{
  vector<double> m;
  vector<double> n;
  for (int i = 0; i < 10000; i++) {
    m.emplace_back(static_cast<double>(rand() % 20) / 10000);
    n.emplace_back(static_cast<double>(rand() % 20) / 10000); }
  double sum = 0;
  clock_t start = clock();
  for (size_t i = 0; i < m.size(); i++) {
    sum += m[i] * n[i];
  }
  clock_t end = clock();
  cout << end - start << ", " << sum << endl;
  sum = 0;
  start = clock();
  for (size_t i = 0; i < m.size(); i++) {
    if (m[i] >= std::numeric_limits<double>::min() && n[i] >= std::numeric_limits<double>::min()) {
      sum += m[i] * n[i];
    }
  }
  end = clock();
  cout << end - start << ", " << sum << endl;
  return 0;
}
