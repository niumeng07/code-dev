#include "Solution.h"
#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> input({1, 2, 3, 4, 5, 6});
  Node *head = BuildList(input);
  PrintList(head);
  Node *r = ReverseList(head);
  PrintList(r);
}
