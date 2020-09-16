#include <iostream>

#include "0707_design_linked_list/design_linked_list.h"
#include "gtest/gtest.h"
using namespace std;

void test_get() {
    cout << "test_get-------------" << endl;
    MyLinkedList *l = new MyLinkedList();
    //为空的时候get
    cout << l->get(0) << endl;
    cout << l->get(1) << endl;
    l->addAtHead(1);
    l->addAtHead(2);
    cout << l->get(0) << endl;
    cout << l->get(1) << endl;
    cout << l->get(2) << endl;
    cout << "---------------------" << endl;
}
void test_addAtHead() {
    cout << "test_addAtHead-------------" << endl;
    MyLinkedList *l = new MyLinkedList();
    l->addAtHead(1);
    l->addAtHead(2);
    l->PrintList();
    cout << "---------------------------" << endl;
}

void test_addAtTail() {
    cout << "test_addAtTail-------------" << endl;
    MyLinkedList *l = new MyLinkedList();
    l->addAtTail(1);
    l->addAtTail(2);
    l->PrintList();
    cout << "---------------------------" << endl;
}

void test_addAtIndex() {
    cout << "test_addAtIndex-------------" << endl;
    MyLinkedList *l = new MyLinkedList();
    l->addAtIndex(0, 1);
    l->addAtIndex(0, 2);
    l->addAtIndex(1, 3);
    l->PrintList();
    cout << "----------------------------" << endl;
}

void test_deleteAtIndex() {
    cout << "test_deleteAtIndex-------------" << endl;
    MyLinkedList *l = new MyLinkedList();
    l->addAtIndex(0, 1);
    l->addAtIndex(0, 2);
    l->PrintList();
    cout << "----------------------------" << endl;
}

int main(int argc, char **argv) {
    test_get();
    test_addAtHead();
    test_addAtTail();
    test_addAtIndex();
    test_deleteAtIndex();
    return 0;
}
/*
  +get(int index)
  +addAtHead(int val)
  +addAtTail(int val)
  +addAtIndex(int index,int val)
  +deleteAtIndex(int index)
*/
