#include "Node.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

Node::Node()
{
    this->depth = 0;
    this->isLeaf = true;
    this->childs = map<int, Node*>();
    this->childNum = 0;
    this->data = "";
    this->father = NULL;
}
Node::Node(string data)
{
    this->depth = 0;
    this->isLeaf = true;
    this->childs = map<int, Node*>();
    this->childNum = 0;
    this->data = data;
    this->father = NULL;
}
Node::~Node()
{
    this->father = NULL;
    delete this->father;
}
bool Node::_addChild(Node* child)
{
    this->childs.insert(std::make_pair(childNum, child));
    this->childNum++;
    this->isLeaf = false;
    child->father = this;
    child->_updateNode();
}
void Node::_updateNode()
{
  if(this->father == NULL)
    this->depth = 0;
  else
    this->depth = this->father->depth + 1;

  if(this->childNum == 0 )
    this->isLeaf = true;
  else
  {
    this->isLeaf = false;
    for(int i = 0; i < this->childNum; i++)
    {
      this->childs[i]->_updateNode();
    }
  }
}
Node* Node::_getChildNode(int i)
{
  if( i > this->childNum)
    return NULL;
  return this->childs[i];
}

Node* Node::_getFather()
{
  if(this->father == NULL)
    return NULL;
  return this->father;
}
int Node::_depth()
{
    return this->depth;
}
bool Node::_isLeaf()
{
    return this->isLeaf;
}
map<int, Node*> Node::_childs()
{
    return this->childs;
}
int Node::_childNum()
{
    return this->childNum;
}
Node* Node::_father()
{
    return this->father;
}
string Node::_data()
{
  return this->data;
}
void Node::_printAll()
{
    cout << "data: " << this->data 
         << "  depth: " << this->depth 
         << "  isLeaf: " << this->isLeaf
         << "  childNum: " << this->childNum
         << "  father: " << ((this->father == NULL)? "NULL":this->father->data)
         << endl;
    if(this->childNum > 0)
    {
        for ( int i = 0; i< this->childNum; i++)
        {
            this->childs[i]->_printAll();
        }
    }
}

