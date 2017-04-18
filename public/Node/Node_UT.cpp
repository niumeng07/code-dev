#include "Node.h"

int UT_TEST()
{
    Node node(string("Root"));
    node._addChild(new Node("C1"));
    Node node2(string("C2"));
    node2._addChild(new Node("C3-2"));
    node._addChild(&node2);

    Node node3(string("C3"));
    node._addChild(&node3);
    Node node4(string("C3-1"));
    node._getChildNode(2)->_addChild(&node4);
    node._printAll();
    return 0;
}
