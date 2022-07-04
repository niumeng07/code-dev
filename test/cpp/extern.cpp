#include <iostream>

using namespace std;

int a = 10;

void test() {
  a = 11;
}

int main(int argc, char *argv[])
{
  test()
  cout << "main:" << a << endl;
  a = 20;
  return 0;
}
