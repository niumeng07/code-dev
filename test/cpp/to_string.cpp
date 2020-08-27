#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
  int x = 1;
  cout << "x=" + std::to_string(x) << endl;

  cout << "false:" << to_string(false) << endl;
  cout << "true:" << to_string(true) << endl;
  return 0;
}
