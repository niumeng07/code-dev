#include <iostream>
#include <vector>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        //第一步，找到中间的那个节点
    }
};
ListNode* BuildList(vector<int> input){
    if(input.empty())
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
    ListNode* head = BuildList({-10, -3, 0, 5, 9});
    Solution su;
    TreeNode* root = su.sortedListToBST(head);
}
