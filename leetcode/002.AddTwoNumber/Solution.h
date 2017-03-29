#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}

    void print()
    {
        ListNode* tmp = this->next;
        std::cout << this->val << "->"<< std::ends;
        if(tmp != NULL)
            tmp->print();
        else
            std::cout << std::endl;

    }
};

class Solution {
public:
    int andOne = 0;
    ListNode* addTwoNumbers(ListNode* left, ListNode* right) {
        if(left == NULL && right == NULL)
        {
            if(this->andOne == 1)
            {
                ListNode* result = new ListNode(this->andOne);
                return result;
            }
            else
                return NULL;
        }
        
        if(left == NULL) 
        {
            ListNode* result = new ListNode( (0  + right->val + this->andOne)%10);
            this->andOne = (0 + right->val + this->andOne)/10;
            result-> next = addTwoNumbers(NULL, right->next);
            return result;
        }
        if(right == NULL) 
        {
            ListNode* result = new ListNode( (left->val + 0 + this->andOne)%10);
            this->andOne = (left->val + 0 + this->andOne)/10;
            result-> next = addTwoNumbers(left->next, NULL);
            return result;
        }

        ListNode* result = new ListNode( (left->val + right->val + this->andOne)%10);
        this->andOne = (left->val + right->val + this->andOne)/10;
        result-> next = addTwoNumbers(left->next, right->next);


        return result;
    }
};
