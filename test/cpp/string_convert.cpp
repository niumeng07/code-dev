#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
  string x = "1.23";
  string y = "1";
  cout << atof(x.c_str()) << endl;
  cout << std::stof(x) << endl;
  cout << std::stoi(y) << endl;
  return 0;
}
