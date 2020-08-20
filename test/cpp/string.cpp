#include <iostream>
#include <vector>
#include <string>
#include <sstream>
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

  std::cout << "----------" << std::endl;
  std::ostringstream ss;
  vector<int> x{1,0,0};
  for (int i = 0; i < x.size(); i++) {
    ss << i+1 << ":10000:" << x[i] << ";";
  }
  std::cout << line +";" + ss.str() << endl;
  return 0;
}
