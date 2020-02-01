#include <iostream>
using namespace std;

class Node {
public:
  int val;
  Node* next;
  Node(int v, Node* n) {
    val = v;
    next = n;
  }
  Node(int v) { val = v; next = nullptr; }
};

class MyLinkedList {
public:
  Node* head;
  MyLinkedList() { head = nullptr; }
  void ClearList() { head = nullptr; }

  void PrintList() {
    Node* iter = head;
    while (iter != nullptr) {
      cout << iter->val << "\t";
      iter = iter->next;
    }
    cout << endl;
  }

  int get(int index) {
    Node* iter = head;
    int i = 0;
    if (index < 0 || iter == nullptr)
      return -1;
    while (true) {
      if (i < index && iter != nullptr) {
        i++;
        iter = iter->next;
      } else if(iter == nullptr) {
        return -1;
      } else {
        break;
      }
    }
    return iter->val;
  }

  void addAtHead(int val) {
    if (head == nullptr) {
      head = new Node(val);
    } else {
      Node* n = new Node(val);
      n->next = head;
      head = n;
    }
  }

  void addAtTail(int val) {
    if (head == nullptr)
      head = new Node(val);
    else {
      Node* iter = head;
      while (iter->next != nullptr)
        iter = iter->next;
      iter->next = new Node(val);
    }
  }

  void addAtIndex(int index, int val) {
    int i = 1;
    Node* iter = head;
    Node* pre = head;
    if (index == 0) {
      this->addAtHead(val);
      return;
    }
    if(iter == nullptr) return;
    while (true) {
      if(i < index) {
        if(iter->next == nullptr)
          return;
        i++;
        pre = iter;
        iter = iter->next;
      } else {
        pre->next = (iter->next == nullptr) ? nullptr : iter->next;
        return;
      }
    }
  }

  void deleteAtIndex(int index) {
    if (head == nullptr)
      return;
    if (index == 0) {
      head = head->next;
      return;
    }

    Node* iter = head;
    int i = 0;
    while (true) {
      if (i + 1 == index) {
        if (iter->next->next != nullptr)
          iter->next = iter->next->next;
        else
          iter->next = nullptr;
        return;
      } else {
        i++;
        if (iter->next != nullptr)
          iter = iter->next;
        else
          return;
      }
    }
  }

};
