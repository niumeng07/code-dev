#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

// void test() {
//   std::map<string, string> _mp;
//   _mp["KeyA"] = "ValueA";
//   _mp["KeyB"] = "ValueB";
//   _mp["KeyC"] = "ValueC";
//   _mp["KeyD"] = "ValueD";
//
//   std::cout << _mp.size() << std::endl;
//   srand(time(NULL));
//   for (int i = 0; i < 100; i++)
//     cout << rand() % _mp.size() << endl;
//   int index = rand() % _mp.size();
//   auto item = _mp[index];
//   return;
// }

void test2() {
  std::map<int, std::map<int, std::vector<int>>> mpFeedsRecordPosition;
  mpFeedsRecordPosition = *(new std::map<int, std::map<int, std::vector<int>>>);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 0; j++) {
      mpFeedsRecordPosition[i][j].push_back(10 * i + j);
    }
  }
  for (auto& _pair : mpFeedsRecordPosition) {
    int X = _pair.first;
    auto& Js = _pair.second;
    for (auto& _pair2 : Js) {
      auto type = _pair2.first;
      std::vector<int>& positions = _pair2.second;
      if (positions.size() > 0) {
        std::cout << type << "," << positions[0] << std::endl;
      }
    }
  }
  return;
}

void test3() {
  std::map<int, string> x{{1, "1"}};
  std::cout << x[1] << std::endl;
  const std::map<int, string> y = x;
  std::cout << y.at(1) << std::endl;

  const std::unordered_map<int, string> z{{1, "1"}, {2, "2"}};
  std::cout << z.at(1) << std::endl; // const map/unordered_map gets value by .at(key)
  // std::cout << z[1] << std::endl;  // const map/unordered_map can't get value by [] operator.
  // std::cout << y[1] << std::endl;
}
int main(int argc, char* argv[]) {
  // test();
  // test2();
  test3();
  return 0;
}
