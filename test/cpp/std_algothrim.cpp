#include <algorithm>
#include <iostream>
using namespace std;

void test1() {
  int16_t user_tag_num = 10;
  cout << std::min(user_tag_num, int16_t(100)) << endl;
}
int main(int argc, char *argv[])
{
  test1();
  return 0;
}
