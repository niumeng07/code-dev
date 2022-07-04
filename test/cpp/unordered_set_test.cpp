#include <unordered_set>
#include <iostream>

using namespace std;

void test1() {
  std::unordered_set<long> grayIds;
  grayIds.insert(2535189);
  grayIds.insert(2535180);
  grayIds.insert(2535187);
  if (grayIds.find(2535188L) != grayIds.end()) {
    cout << "grayIds: 2535188L found." << endl;
  }
}

int main(int argc, char *argv[])
{
  test1();
  return 0;
}
