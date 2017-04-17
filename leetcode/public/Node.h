#ifndef __NODE__H__
#define __NODE__H__
#include <map>
using namespace std;
class Node
{
public:
    map<int, Node*> childs;
    Node* father;
    Node(){}
    ~Node(){}

};
#endif

