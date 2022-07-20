#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class DP {
public:
  unordered_map<int, uint64_t> mm;
  DP() {
    mm[0] = 0;
    mm[1] = 1;
  }
  int F(int n) {
    if (mm.find(n) != mm.end()) {
      return mm[n];
    }
    mm[n] = F(n - 1) + F(n - 2);
    return mm[n];
  }
};

int main() {
  cout << "Hello World!" << endl;
  cout << DP().F(30) << endl;
}
