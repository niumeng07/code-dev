#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
  std::vector<vector<int>> vv;
  vv.push_back({1, 2, 3});
  vv.push_back({3, 2, 3});
  vv.push_back({8, 2, 3});

  std::vector<vector<int>> vv2 = vv;
  vv2.push_back({1, 2, 3});

  for (const auto& v : vv) {
    vv2.push_back(v);
  }

  for (std::vector<vector<int>>::iterator it = vv2.begin(); it != vv2.end(); ++it) {
    (*it)[0] = 11;
    std::cout << (*it)[0] << endl;
  }
  for (std::vector<vector<int>>::iterator it = vv.begin(); it != vv.end(); ++it) {
    std::cout << (*it)[0] << endl;
  }


  return 0;
}
