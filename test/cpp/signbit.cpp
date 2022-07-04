#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
  double cas_score = std::signbit(1.0) ? 0.000001 : 1.0;
  cout << cas_score << endl;
  cas_score = std::signbit(-0.1) ? 0.000001 : -0.1;
  cout << cas_score << endl;
  return 0;
}
