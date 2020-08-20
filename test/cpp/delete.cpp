#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
  int x = *(new int(2));
  cout << x << endl;
  return 0;
}
