#include "Node.h"
#include <stdlib.h>
#include <iostream>

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
    child->depth = this->depth + 1;
    child->isLeaf = true;
    child->father = this;
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
void Node::printAll()
{
    cout << this->data << endl;
    if(this->childNum > 0)
    {
        for ( int i = 0; i< this->childNum; i++)
        {
            this->childs[i]->printAll();
        }
    }
}




