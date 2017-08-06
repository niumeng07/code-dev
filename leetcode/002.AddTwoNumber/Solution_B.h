#include <iostream>

using namespace std;
class Node{
public:
    Node* next;
    int   current;
    Node(): next(NULL), current(0){}
    Node(int val) : next(NULL), current(val) {}
};
void printNode(Node* it){
    while(it != NULL)
    {
        cout << it->current << "  " ;
        it = it->next;
    }
}
class Solution_B{
public:
    Node* addTwoNumbers( Node* left, Node* right){
        int andOne = 0;
        Node* result = new Node(0);
        Node* iter = result;
        while(true){
            if( left != NULL && right != NULL){
                int next = (left->current + right->current + andOne) % 10;
                iter->next = new Node(next);
                andOne = (left->current + right->current + andOne)/10;
                left = left->next;
                right = right->next;
                iter = iter->next;
                continue;
            }
            if(left != NULL){
                int next = (left->current + andOne)%10;
                iter->next = new Node(next);
                andOne = (left->current + andOne)/10;
                left = left->next;
                iter = iter->next;
                continue;}
            if(right != NULL){
                int next = (right->current + andOne)%10;
                iter->next = new Node(next);
                andOne = (right->current + andOne)/10;
                right = right->next;
                iter = iter->next;
                continue;
            }
            if( left== NULL && right == NULL){
                if( andOne > 0)
                    iter->next = new Node(andOne);
                break;
            }
        }
        return result->next;
    }
};
