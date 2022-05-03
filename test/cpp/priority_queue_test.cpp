#include <iostream>
#include <queue>
#include <random>

using namespace std;

void test1() {
  std::priority_queue<int> q;
  for (int i = 0; i < 10; i++) {
    q.push(rand() % 100);
  }
  while (!q.empty()) {
    cout << q.top() << endl;
    q.pop();
  }
}

int main(int argc, char *argv[]) {
  test1();
  return 0;
}
