#include <time.h>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

void test1() {
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

}

void test2() {
  vector<int> x;
  x.reserve(0);
  x.insert(x.begin() + 100, 0);
}

void test3() {
  vector<int> x;
  x.push_back(1);
  cout << x.size() << endl;
  x.pop_back();
  cout << x.size() << endl;
}
int main(int argc, char* argv[]) {
  test3();
  return 0;
}
