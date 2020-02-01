#ifndef __VECTOR_H__
#define __VECTOR_H__
#include "Node1/Node.h"
#include <iostream>

const uint32_t defaultCapacity = 100;

template <class T1> class Vector {
private:
  uint32_t _size;
  uint32_t _capacity;

  T1 *_head;
  T1 *_tail;

public:
  Vector();

  bool PushBack(T1 ele);
  uint32_t Size();
  uint32_t Capacity();

  T1 Tail();

  bool Resize(uint32_t cap);
};

template <class T1> Vector<T1>::Vector() {
  _size = 0;
  _capacity = defaultCapacity;
  _head = (T1 *)malloc(_capacity * sizeof(T1));
  _tail = _head;
}

template <class T1> uint32_t Vector<T1>::Size() { return _size; }

template <class T1> uint32_t Vector<T1>::Capacity() { return _capacity; }

template <class T1> bool Vector<T1>::PushBack(T1 ele) {
  *(_head + _size) = ele;
  _size++;
  _tail = _head + _size;
  if (_size == _capacity) {
    return Resize(_capacity + defaultCapacity);
  }
  return true;
}

template <class T1> T1 Vector<T1>::Tail() {
  if (_size == 0) {
    return T1(NULL);
  }
  return *(_tail - 1);
}

template <class T1> bool Vector<T1>::Resize(uint32_t newCap) {
  _capacity = newCap;
  T1 *tmp_head = (T1 *)malloc(newCap * sizeof(T1));
  for (int i = 0; i < _size; i++) {
    *(tmp_head + i) = *(_head + i);
  }
  _head = tmp_head;
  tmp_head = NULL;
  delete tmp_head;
  return true;
}
#endif
