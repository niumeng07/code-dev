#include <iostream>
#include <vector>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

int repartition(vector<ListNode*>& input, int left, int right){
    int middle = right;
    int i = left, j = right - 1;
    while(true){
        if(i >= j )
            break;
        if(input[i]->val > input[middle]->val && input[j]->val < input[middle]->val){
            swap(input[i], input[j]);
            i++;
            j--;
        } else if(input[i]->val < input[middle]->val){
            i++;
        } else if(input[j]->val > input[middle]->val){
            j--;
        }
    }
    if(input[j] > input[middle])
        swap(input[j], input[middle]);
    return j;
}
void quick_sort(vector<ListNode*>& input, int left, int right){
    if(right <= left)
        return;
    if(right == left + 1){
        if(input[left]->val > input[right]->val)
            swap(input[left], input[right]);
        return;
    }
    if(right > left + 1){
        int middle = repartition(input, left, right);
        quick_sort(input, left, middle);
        quick_sort(input, middle, right);
        return;
    }
}
void print_listnode(ListNode* head){
    ListNode* iter = head;
    while(iter != NULL){
        cout << iter->val << "\t";
        iter = iter->next;
    }
    cout << endl;
}
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        vector<ListNode*> listnode_vec;
        ListNode* iter = head;
        while(iter!=NULL){
            listnode_vec.push_back(iter);
            iter = iter->next;
        }
        //采用quick_sort方式
        quick_sort(listnode_vec, 0, listnode_vec.size() - 1 );
        head = listnode_vec[0];
        iter = head;
        for(int i = 1; i < listnode_vec.size(); i++){
            iter->next = listnode_vec[i];
            iter = iter->next;
        }
        iter->next = NULL;
        return head;
    }
};

int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(3);
    head->next->next = new ListNode(2);
    print_listnode(head);
    Solution su;
    su.sortList(head);
    print_listnode(head);
}
