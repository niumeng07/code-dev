#ifndef __NODE__H__
#define __NODE__H__
#include <map>
#include <string>
using namespace std;
class Node
{
public:
    Node();
    Node(string data);
    ~Node();

    bool _addChild(Node* child);//在当前节点下添加单节点Node.(ps: 新添加的节点不能再有孩子节点)
    int _depth();
    bool _isLeaf();
    map<int, Node*> _childs();
    int _childNum();
    Node* _father();
    void _printAll();// 从当前节点开始打印所子节点
    void _updateNode();
    Node* _getChildNode(int i);//获取当前Node的第i个子Node
    Node* _getFather();
    string _data();

private:
    int depth; //标志当前节点深度, root节点为0，第一代子节点为1, ...
    bool isLeaf; //标志当前节点是否为叶子节点

    map<int, Node*> childs;//保存孩子节点的map
    int childNum; // 标志当前节点的孩子数目，若isLeaf = True, 则该值为0
    Node* father;

    string data; //当前节点数据，template<class T> 修改string
};
#endif
