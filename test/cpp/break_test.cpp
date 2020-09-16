#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  int x = 1;
  switch (x) {
    case 1:
      std::cout << 1 << std::endl;
      break;
    case 2:
      std::cout << 2 << std::endl;
      break;
    default:
      std::cout << 3 << std::endl;
  }
  return 0;
}
