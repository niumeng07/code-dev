#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
  for (int i : {1, 2, 6, 3, 100, 49}) {
    cout << i << ",";
  }
  cout << endl;
  return 0;
}
