#include <vector>
#include <iostream>
#include <unistd.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
void printList(ListNode* head){
    ListNode* iter = head;
    while(iter!=NULL){
        cout << iter->val << "\t";
        iter = iter->next;
    }
    cout << endl;
}

ListNode* ReverseList(ListNode* head){
    if(head == NULL || head->next == NULL)
        return head;
    ListNode* pre = head;
    ListNode* curr = head->next;
    while (curr->next != NULL) {//是最后一个结点了
        ListNode* tmp = curr->next;
        curr->next = pre;
        pre = curr;
        curr = tmp;
    }
    curr->next = pre;
    head->next = NULL;
    return curr;

}
void MergeList(ListNode* head, ListNode* insert){
    ListNode* left = head;
    ListNode* right = insert;
    while(right != NULL){
        ListNode* tmp = left->next;
        ListNode* rtmp = right->next;
        left->next = right;
        right->next = tmp;
        left = tmp;
        right = rtmp;
    }
}
class Solution {
public:
    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return;
        //表一分爲二
        ListNode* head2 = head;
        ListNode* iter = head;
        while(true){
            if(iter->next == NULL || iter == NULL)
                break;
            if( head2 == NULL || head2->next == NULL || head2->next->next == NULL)
                break;
            iter = iter->next;
            head2 = head2->next->next;
        }
        head2 = iter->next;
        iter->next = NULL;
        //List2倒序
        head2 = ReverseList(head2);

        //merge两个List
        MergeList(head, head2); }
};

ListNode* buildList(vector<int> &input){
    if(input.size() == 0)
        return NULL;
    ListNode* head = new ListNode(input[0]);
    ListNode* iter = head;
    for(int i = 1; i < input.size(); i++){
        iter->next = new ListNode(input[i]);
        iter = iter->next;
    }
    return head;
}
int main(){
    //vector<int> tmp({1,2,3,4,5});
    vector<int> tmp({1,2,3});
    ListNode* head = buildList(tmp);
    Solution su;
    printList(head);
    su.reorderList(head);
    printList(head);
}
