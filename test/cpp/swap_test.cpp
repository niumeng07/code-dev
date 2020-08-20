#include <list>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
  std::list<int> tmp;
  std::list<int> lst({1,2,3});

  std::cout << "---before swap----" << std::endl;
  for(auto x : lst) {
    std::cout << x << ";";
  }
  std::cout << std::endl;

  lst.swap(tmp);
  std::cout << "---after swap----" << std::endl;
  for(auto x : lst) {
    std::cout << x << ";";
  }
  std::cout << std::endl;
  return 0;
}
