#include <vector>
#include <iostream>
#include<algorithm> // for copy() and assign() 
#include<iterator> // for back_inserter

using namespace std;

int main(int argc, char* argv[]) {
  vector<int> x({1, 2, 3, 4, 5, 6});
  vector<int> y({11, 21, 31, 41, 51, 61});
  vector<int> z;

  z.reserve(x.size() + y.size());
  std::copy(x.begin(), x.begin() + 3, back_inserter(z));
  std::copy(y.begin(), y.begin() + 3, back_inserter(z));
  std::copy(x.begin() + 3, x.end(), back_inserter(z));
  std::copy(y.begin() + 3, y.end(), back_inserter(z));

  for (auto i : z) {
    std::cout << i << ",";
  }
  std::cout << std::endl;
  return 0;
}
