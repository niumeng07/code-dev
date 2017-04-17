#ifndef __NODE__H__
#define __NODE__H__
#include <map>
#include <string>
using namespace std;
template <class T>
class Node
{
public:
    Node(){}
    ~Node(){}

    map<int, Node*> childs; //孩子节点队列
    int child_num;          //孩子节点数量
    Node* father;           //父节点
    T curr;            //当前节点内容
};
#endif

