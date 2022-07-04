#include <iostream>
#include <unordered_map>
using namespace std;
struct Test {
  int t1;
  std::unordered_map<int, int> t2;
};

void test1() {
  Test* t1 = new Test();
  shared_ptr<Test> t2 = std::shared_ptr<Test>(t1);
  cout << t2->t1 << endl;
  for (const auto& x : t2->t2) {
    cout << x.first << ", " << x.second << endl;
  }
}

void test2() {
 std::shared_ptr<Test> t1 = std::make_shared<Test>();
 cout << t1->t1 << endl;
}

int main() {
  test2();
  return 0;
}
