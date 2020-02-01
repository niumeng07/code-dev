#ifndef __NODE_H__
#define __NODE_H__
#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

template <class T1, class T2> class Node {
private:
  T1 element;

public:
  Node(T1 const &);
  Node();
};

template <class T1, class T2> Node<T1, T2>::Node(T1 const &elem) {
  this->element = elem;
}
template <class T1, class T2> Node<T1, T2>::Node() {}
#endif
