#include <iostream>

using namespace std;

class A {
public:
  virtual void test1() = 0;
  virtual void test2() = 0;
};

class B : public A {
public:
  virtual void test1() {
    
  }
  virtual void test2() {
    
  }
  void test3() {
    
  }
};

int main(int argc, char *argv[]) {
  B b; 
  b.test1();
  b.test2();
  b.test3();
  return 0;
}
