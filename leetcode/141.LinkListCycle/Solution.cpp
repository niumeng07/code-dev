#include <iostream>
using namespace std;
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};
class Solution 
{
public:
    bool hasCycle(ListNode *head)
    {
        if(head == NULL || head->next == NULL) return false;
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast->next != NULL && fast->next->next != NULL && slow->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow) return true;
        }
        return false;
    }
};
int main()
{
    ListNode *head = new ListNode(0);
    ListNode *first = new ListNode(1);
    ListNode *second = new ListNode(2);
    head->next = first;
    first->next = second;
    Solution su;
    if(su.hasCycle(head))
        cout << "yes" << endl;
    else
        cout << "no" << endl;
    second->next = head;
    if(su.hasCycle(head))
        cout << "yes" << endl;
    else
        cout << "no" << endl;
}
