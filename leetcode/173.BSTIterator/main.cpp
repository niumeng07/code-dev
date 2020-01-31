#include "Solution.h"
#include <vector>

using namespace std;
int main() {
  vector<int> list({1, 82, 487, 83, 92, 2, 6, 9, 100, 108});
  TreeNode *root = build_searchtree(list); //是一个搜索树
  BSTIterator i = BSTIterator(root);
  cout << "build class." << endl;
  while (i.hasNext())
    cout << i.next() << ", ";
  return 0;
}
