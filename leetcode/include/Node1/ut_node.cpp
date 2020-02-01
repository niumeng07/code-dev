#include "Node1/Node.h"
#include <vector>
using namespace std;

int main(int argc, char **argv) {

  Node<int, int> node1(1);
  Node<vector<int>, int> node2({1, 2, 3});
  return 0;
}
