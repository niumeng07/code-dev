#include <boost/algorithm/string.hpp>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;
using namespace boost;

int main() {
  ifstream is("test.txt");
  char buffer[256];
  while (is) {
    is.getline(buffer, 1000);
    cout << buffer << endl;
  }

  cout << "-------------------------------------" << endl;
  string s = "a,b,c,e,f";
  vector<string> fields;
  split(fields, s, is_any_of(","));
  for (auto item : fields) {
    cout << item << "|";
  }
  cout << endl;
  split(fields, s, is_any_of(" ,"));
  for (auto item : fields) {
    cout << item << "|";
  }
  cout << endl;
  split(fields, s, is_any_of(" ,"), token_compress_on);
  for (auto item : fields) {
    cout << item << "|";
  }
  cout << endl;
  return 0;
}
