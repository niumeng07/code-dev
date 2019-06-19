#include <iostream>
#include <string>
using namespace std;

int main() {
  string line = "12345";
  cout << line.size() << "\t" << line.capacity() << endl;
  line.reserve(200);
  cout << line.size() << "\t" << line.capacity() << endl;
  size_t offset = line.find((char)2);
  cout << line << endl;
  cout << offset << endl; // 18446744073709551615
  char xx = (char)2; 
  cout << xx << endl;
  return 0;
}
