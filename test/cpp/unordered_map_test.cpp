#include <unordered_map>
#include <iostream>
#include <vector>
#include <string>
#include <time.h>
#include <random>

using namespace std;

void test1() {
  unordered_map<uint64_t, vector<float>> x;
  vector<float> v;
  for (uint64_t i = 0; i < 10; i++) {
    v.clear();
    for (uint64_t j = 0; j < 10; j++) {
      v.emplace_back(j * 10 + i);
    }
    x.insert(std::make_pair(i, v));
  }
  for (const auto& item : x) {
    cout << item.first << ": ";
    for (const auto& v: item.second) {
      cout << v << ",";
    }
    cout << endl;
  }
}

int main(int argc, char *argv[])
{
  test1();
  return 0;
}
