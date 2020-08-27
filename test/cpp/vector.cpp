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
  cout << (end - start) << endl;
  start = clock();
  vector<float> vc2;
  for (int i = 0; i < vc1.size(); i++) {
    vc2.push_back(rand());
  }
  end = clock();
  cout << (end - start) << endl;
  unordered_map<int, int> umap;

}
void test2() {
  std::vector<int> x{1,2,3};
  x.resize(2);
  for(auto i : x) {
    std::cout << i << ", ";
  }
  std::cout << std::endl;
}
void test3() {
  vector<int> v{1,2,3,4,0,-1,-2};
  for(auto x: v) {
    std::cout << x;
  }
  std::cout << std::endl;
}
void test4() {
  vector<int> p;
  for (int i = 0; i < 10; i++) {
    p.emplace_back(i);
  }
  cout << p.size() << endl;
  vector<int> a;
  a.reserve(5);
  vector<int> b;
  b.reserve(5);
  std::copy(p.begin(), p.begin() + 5, std::back_inserter(a));
  std::copy(p.begin() + 5, p.end(), std::back_inserter(b));
  for (auto x : a) {
    cout << x << ", " << ends;
  }
  cout << endl;
  for (auto x : b) {
    cout << x << ", " << ends;
  }
  cout << endl;
}

void test5() {
  vector<int> x(5, 0);
  x[0]=0;
  x[1]=1;
  x[2]=2;
  x[3]=3;
  x[4]=4;
  std::cout << x.size() << std::endl;
  for (auto i : x) {
    std::cout << i << ",";
  }
  std::cout << std::endl;
}

int main(int argc, char* argv[]) {
  // test2();
  // test3();
  // test4();

  // for (int a : {1,2,3}) {
  //   std::cout << a << std::endl;
  // }
  test5();
  return 0;
}
