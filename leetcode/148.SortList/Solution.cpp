#include <iostream>
#include <vector>
#include <time.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

int repartition(vector<ListNode*>& input, int left, int right){
    int middle = right;
    int i = left, j = right - 1;
    while(true) {
        if(i >= j )
            break;
        if(input[i]->val > input[middle]->val && input[j]->val < input[middle]->val){
            swap(input[i], input[j]);
            i++;
            j--;
        } else if(input[i]->val <= input[middle]->val) {
            i++;
        } else if(input[j]->val >= input[middle]->val) {
            j--;
        }
    }
    if(input[j]->val > input[right]->val)
        swap(input[j], input[right]);
    return i;
}
void quick_sort(vector<ListNode*>& input, int left, int right) {
    if(right <= left)
        return;
    if(right > left + 1) {// 3 1 0
        int middle = repartition(input, left, right);//middle always 0
        quick_sort(input, left, middle);
        quick_sort(input, middle, right);//这里就是死循环
    } else if(right == left + 1) {
        if(input[left]->val > input[right]->val)
            swap(input[left], input[right]);
    }
}
void print_listnode(ListNode* head) {
    ListNode* iter = head;
    while(iter != NULL) {
        cout << iter->val << "\t";
        iter = iter->next;
    }
    cout << endl;
}
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head==NULL)
            return NULL;
        vector<ListNode*> listnode_vec;
        ListNode* iter = head;
        while(iter!=NULL){
            listnode_vec.push_back(iter);
            iter = iter->next;
        }
        quick_sort(listnode_vec, 0, listnode_vec.size() - 1 );
        head = listnode_vec[0];
        iter = head;
        for(int i = 1; i < listnode_vec.size(); i++) {
            iter->next = listnode_vec[i];
            iter = iter->next;
        }
        iter->next = NULL;
        return head;
    }
};

int main(){
    vector<int> tmp({1,3,3,1,3,1,3,3,2,3,2,2,1,1,1,3,2,2,1,1,2,2,2,3,3,1,1,2,2,2,1,2,1,1,2,3,3,2,2,3,2,3,2,2,2,1,1,3,2,3,3,1,1,1,2,2,1,2,2,2,2,3,1,3,1,1,1,2,1,2,2,2,1,3,2,2,2,3,3,2,3,3,1,1,2,2,1,2,1,3,2,1,3,3,1,2,1,1,1,1,1,2,1,2,2,2,2,3,3,3,1,1,3,2,1,1,2,1,3,3,2,2,1,3,1,3,1,3,2,2,3,2,3,2,2,1,2,3,1,3,1,2,3,3,2,3,3,3,1,1,2,3,1,2,3,2,1,1,2,3,1,1,3,1,2,2,3,2,1,3,1,2,1,3,2,1,1,2,2,2,1,3,1,3,2,3,3,1,1,3,1,2,1,2,3,1,2,1,1,3,1,3,3,1,1,1,2,2,1,3,1,2,2,3,2,1,3,2,1,3,2,2,3,3,2,2,1,3,2,2,2,2,2,3,2,2,3,1,3,2,1,3,2,1,2,3,3,3,1,2,2,3,1,1,2,2,3,2,1,1,1,1,1,3,2,2,2,1,3,2,1,2,3,2,1,1,2,1,3,3,1,3,1,2,2,1,2,3,2,3,3,1,2,3,2,2,3,3,2,1,3,2,2,2,3,3,3,1,1,2,1,1,2,3,3,3,1,3,2,2,1,2,2,1,2,3,1,3,2,2,3,3,3,1,2,3,2,1,3,1,1,2,2,1,1,1,2,2,3,1,3,1,2,3,3,3,2,2,3,1,1,1,3,2,1,1,3,1,2,3,3,3,2,1,2,3,2,3,2,1,3,2,2,2,2,1,1,3,1,1,1,3,2,2,2,1,2,3,2,3,2,2,1,2,3,2,1,1,3,1,3,3,1,1,1,1,1,2,3,3,3,1,3,2,2,3,1,1,3,1,1,1,3,1,1,2,2,2,1,1,1,1,2,1,3,3,3,1,2,2,2,2,3,3,1,2,2,3,1,3,1,2,1,2,2,3,3,1,3,3,2,1,3,1,1,3,1,2,3,3,3,3,1,1,3,3,3,3,2,2,2,1,1,3,2,2,2,3,1,3,3,3,1,1,3,1,3,2,3,1,2,3,2,2,3,3,3,1,2,1,2,1,2,3,1,2,2,2,1,1,1,2,2,1,2,1,1,1,3,2,1,2,3,2,2,2,1,2,3,2,2,1});
    ListNode* head = new ListNode(tmp[0]);
    ListNode* iter = head;
    for(int i = 1; i < tmp.size(); i++){
        iter->next = new ListNode(tmp[i]);
        iter = iter->next;
    }
    Solution su;
    print_listnode(head);
    clock_t start, end;
    start = clock();
    ListNode* t = su.sortList(head);
    end = clock();
    cout << "time used: " <<  (double)(end - start) / CLOCKS_PER_SEC * 1000000 << " us" << endl;
    print_listnode(t);
}
