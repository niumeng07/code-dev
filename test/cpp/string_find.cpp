#include <string>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
  string x = "123|456";
  if (x.find("123")!=std::string::npos) {
    cout << "find 123";
  } else {
    cout << "not found 123";
  }
  if (x.find("223")!=std::string::npos) {
    cout << "find 223";
  } else {
    cout << "not found 223";
  }
  if (x.find("456")!=std::string::npos) {
    cout << "find 456";
  } else {
    cout << "not found 456";
  }

  return 0;
}
