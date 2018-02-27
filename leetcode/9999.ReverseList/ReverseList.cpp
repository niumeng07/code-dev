#include <iostream>
#include <vector>
#include <unistd.h>
using namespace std;

class Node{
public:
    int val;
    Node* next;
    Node(int x) : val(x), next(NULL) {}
};
void PrintList(Node* input){
    Node* iter = input;
    while(iter!=NULL){
        cout << iter->val << "\t";
        iter = iter->next;
    }
    cout << endl;
}
Node* BuildList(vector<int> &input){
    if(input.size() == 0)
        return NULL;
    Node* head = new Node(input[0]);
    Node* iter = head;
    for(int i = 1; i < input.size(); i++){
        iter->next = new Node(input[i]);
        iter = iter->next;
    }
    return head;
}

Node* ReverseList(Node* head) {
    if(head == NULL)
        return NULL;
    Node* pre = head;
    Node* curr = head->next;
    while (curr->next != NULL) {//是最后一个结点了
        Node* tmp = curr->next;
        curr->next = pre;
        pre = curr;
        curr = tmp;
    }
    curr->next = pre;
    head->next = NULL;
    return curr;
}
int main(){
    vector<int> input({1,2,3,4,5,6});
    Node* head = BuildList(input);
    PrintList(head);
    Node* r = ReverseList(head);
    PrintList(r);
}
