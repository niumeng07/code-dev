#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  for (int i = 0; i < 10; i++) {
    uint32_t move_bit = (i == 2) ? 2 : 1;
    cout << move_bit << endl;
  }
  return 0;
}
