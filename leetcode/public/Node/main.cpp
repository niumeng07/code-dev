#include "Node.h"

int main()
{
    Node node(string("abc"));
    node._addChild(new Node("def"));
    Node node2(string("child1"));
    node2._addChild(new Node("child12"));
    node._addChild(&node2);

    node.printAll();
    return 0;
}
