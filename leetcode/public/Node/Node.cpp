#include "Node.h"
#include <string>
using namespace std;

template <class T>
class Node
{
  Node()
  {
    this->childs = new map<int, *Node>;
    this->child_num = 0;
    this->father = null;
    this->isRoot = true;
    this->isLeaf = true;
  }
  Node( T data)
  {
    this->childs = new map<int, *Node>;
    this->child_num = 0;
    this->father = null;
    this->isRoot = true;
    this->isLeaf = true;
    this->data = data;
  }

  ~Node()
  {
    this->childs = null; del this->childs;
    this->father = null; del this->father;
  }

  int addChild(Node* child)
  {
    this->childs[child_num] = child;
    this->child_num++;
    child->father = this;
    child->isRoot = false;
    if(child->child_num == 0 )
      child->isLeaf = true;
    else
      child->isLeaf = false;
  }

  
};
