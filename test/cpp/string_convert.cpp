#include <iostream>
#include <time.h>

using namespace std;

void test1() {
  string x = "1.23";
  string y = "1";
  cout << atof(x.c_str()) << endl;
  cout << std::stof(x) << endl;
  cout << std::stoi(y) << endl;
}

void test2() {
    string x = "  1.23  ";
    std::cout << bool(stoi(x.c_str())) << std::endl;
    std::cout << bool(stoi(x)) << std::endl;
    std::cout << bool(atoi(x.c_str())) << std::endl;
}

void test3() {
  int z = 0;
  clock_t start = clock();
  for (size_t i = 0; i < 100000; ++i) {
    string x = "10.23";
    int y = atoi(x.c_str());
    z += y;
  }
  clock_t end = clock();
  cout << end - start << endl;

  start = clock();
  for (size_t i = 0; i < 100000; ++i) {
    string x = "10.23";
    int y = stoi(x.c_str());
    z += y;
  }
  end = clock();
  cout << end - start << endl;
  cout << z << endl;
}

int main(int argc, char* argv[]) {
  test3();
  return 0;
}
