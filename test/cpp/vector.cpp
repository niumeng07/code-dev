#include <time.h>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main(int argc, char* argv[]) {
  rand();
  clock_t start, end;
  start = clock();
  vector<float> vc1(10000, 0.0);

  for (int i = 0; i < vc1.size(); i++) {
    vc1[i] = rand();
  }
  end = clock();
  cout << end - start << endl;
  start = clock();
  vector<float> vc2;
  for (int i = 0; i < vc1.size(); i++) {
    vc2.push_back(rand());
  }
  end = clock();
  cout << end - start << endl;
  unordered_map<int, int> umap;
  return 0;
}
