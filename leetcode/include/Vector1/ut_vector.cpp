#include "Vector1/Vector.h"
#include <iostream>

int main(int argc, char *argv[]) {
  Vector<int> v;
  std::cout << v.Size() << std::endl;
  std::cout << v.Capacity() << std::endl;
  std::cout << v.Tail() << std::endl;
  v.PushBack(1);
  std::cout << v.Size() << std::endl;
  std::cout << v.Capacity() << std::endl;
  std::cout << v.Tail() << std::endl;
  v.Resize(400);
  std::cout << v.Size() << std::endl;
  std::cout << v.Capacity() << std::endl;
  std::cout << v.Tail() << std::endl;
  return 0;
}
