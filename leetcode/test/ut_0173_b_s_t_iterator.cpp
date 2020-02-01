#include "0173_b_s_t_iterator/b_s_t_iterator.h"
// #include "Node/Node.h"
#include "gtest/gtest.h"
#include <vector>

using namespace std;
int main(int argc, char **argv) {
  vector<int> list({1, 82, 487, 83, 92, 2, 6, 9, 100, 108});
  Node *root = build_searchtree(list); //是一个搜索树
  BSTIterator i = BSTIterator(root);
  cout << "build class." << endl;
  while (i.hasNext())
    cout << i.next() << ", ";
  return 0;
}
