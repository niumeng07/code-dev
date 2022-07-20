#include <iostream>
using namespace std;
class Node {
public:
  int value;
  Node* next;
  Node(int v) {value = v;}
};

// 反转链表
Node* revertList(Node* head) {
  if (head == nullptr || head->next == nullptr) return head;
  Node* iter = head;
  Node* in = head->next;
  Node* inn = head->next->next;   // 有可能为null
  in->next = iter;
  iter->next = revertList(inn);
  return in;
}

void PrintList(Node* head) {
  Node* iter = head;
  while (iter) {
    cout << iter->value << ", ";
    iter = iter->next;
  }
  cout << endl;
}

int main() {
    std::cout << "hello world" << std::endl;
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    revertList(head);
    PrintList(head);
    return 0;
}

