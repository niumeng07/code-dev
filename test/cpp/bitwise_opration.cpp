#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
  long x = 966367641600;
  cout << (x & 0x00000000ffffffff) << std::endl;
  cout << ((x & 0xffffffff00000000) >> 32) << std::endl;
  return 0;
  int a = 9;
  int b = 3;

  a = (a << 1);
  b = (b << 1);
  cout << a << "\t" << b << endl;
  a = (a >> 2); //4
  b = (b >> 2); //1
  cout << a << "\t" << b << endl;
  return 0;
}
