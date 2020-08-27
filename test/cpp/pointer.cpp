#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char* argv[]) {
  vector<int> A({1, 2, 3});
  vector<int> B({4, 5, 6});
  vector<int>* p = nullptr;
  p = &A;
  cout << (*p)[0] << endl;
  p = &B;
  cout << (*p)[0] << endl;
  return 0;
}
