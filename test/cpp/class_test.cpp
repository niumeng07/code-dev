#include <iostream>
#include <vector>
using namespace std;

#define AAA 1
#define B   34
template <class T>
void func1(T &x, T &y) {
  T temp;
  temp = x;
  x = y;
  y = temp;
}

class Car {
  public:
  int x;
  Car(int y, int z) : x(y) { cout << "init" << endl; }
  void echo() { std::cout << "echo" << endl; }
};

class Bus {
  public:
  int x = 9;
  Bus() {}
};

void test1() {
  // Car *p=new Car(1,2);
  // p->echo();

  vector<int> vec({1, 3, 2, 9, 2});
  int x = 0;
  for (int i = 0; i < vec.size(); i++) {
    int xx = 0;
    for (int j = 0; j < vec.size(); j++) {
      xx += vec[i] * vec[j];
    }
    x += xx;
  }
  cout << x << endl;
  cout << 17 * 17 << endl;
  while (1) {}
  while (1) { cout << 0 << endl; }
}

void test2() {
  Bus bus;
  cout << bus.x << endl;
  Bus *bus2 = new Bus();
  cout << bus2->x << endl;
  cout << 1 << 2 << 3 << 4 << 5 << 6 << 7 << 8 << 9 << 10 << 11 << 12 << 13
       << 14 << 15 << 16 << 17 << 18 << 19 << 20 << 21 << 22 << 23 << 24 << 25
       << 26 << 27 << 28 << 29 << 29 << 30 << 31 << 32 << 33 << 34 << 35 << 36
       << 37 << 38 << 39 << 40 << 41 << 42 << 43 << 44 << 45 << 45 << 46 << 47
       << 48 << 48 << 48 << 48 << 48 << 48 << 48 << 48 << 48 << 48 << 48 << 48
       << 48 << endl;
  int a = 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 + 10 + 11 + 12 + 13 + 14 + 15 + 16
          + 17 + 18 + 19 + 20 + 21 + 22 + 23 + 23 + 23 + 23 + 23 + 23 + 23 + 23
          + 23;
}

int main() {
  test2();
  return 0;
}
