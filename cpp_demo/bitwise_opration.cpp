#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
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
