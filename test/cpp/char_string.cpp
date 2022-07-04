#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
  char x[10] = "12344566";
  cout << (const char*)x << endl;
  int y[2] = {123, 345};
  cout << (const char*)&y[0] << endl;
  return 0;
}
