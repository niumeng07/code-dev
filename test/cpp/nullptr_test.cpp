#include <iostream>

using namespace std;

class Test {};

int main(int argc, char* argv[]) {
  Test* test = nullptr;
  if (test) {
    cout << "1" << endl;
  }
  test = new Test();
  if (test) {
    cout << "2" << endl;
  }
  return 0;
}
