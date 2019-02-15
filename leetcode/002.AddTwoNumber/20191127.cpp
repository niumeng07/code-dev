#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    Node() : next(NULL), value(0) {}
    Node(int x): next(NULL), value(x) {}
    Node* next;
    int value;
};
class TList {
public:
    TList():head(NULL) {}
    TList(vector<int> input) {
        if(input.size() == 0) {
            head  = NULL;
        } else {
            head = new Node(input[0]);
            Node* iter = head;
            for(int i = 1; i < input.size(); i++) {
                iter->next = new Node(input[i]);
                iter = iter->next;
            }
        }
    }
    void printTlist() {
        Node* iter = head;
        while(iter != NULL) {
            cout << iter->value << "\t";
            iter = iter->next;
        }
        cout << endl;
    }
    Node* head;
};

TList addList(TList left, TList right) {
    int carry = 0;
    Node *iterl = left.head;
    Node *iterr = right.head;
    int sum = 0;
    while(iterl != NULL && iterr != NULL) {
        sum = iterl->value + iterr->value + carry;
        iterl->value = sum % 10;
        iterr->value = iterl->value;
        carry = sum / 10;
        iterl = iterl->next;
        iterr = iterr->next;
    }
    if (iterl != NULL) {
        while(iterl != NULL) {
            sum = iterl->value + iterr->value + carry;
            iterl->value = sum % 10;
            carry = sum / 10;
            iterl = iterl->next;
        }
        if(carry > 0) {
            iterl->next = new Node(carry);
            return left;
        }
    } else if (iterr != NULL) {
        while(iterr != NULL) {
            sum = iterl->value + iterr->value + carry;
            iterl->value = sum % 10;
            carry = sum / 10;
            iterr = iterr->next;
        }
        if(carry > 0) {
            iterr->next = new Node(carry);
            return right;
        }
    }
    
    return left;
}
int main(int argc, char *argv[]) {
    TList _list1 = TList({2,4,3});
    TList _list2 = TList({5,6,4});
    TList _list3 = addList(_list1, _list2);
    _list3.printTlist();
    return 0;
}
