#include <iostream> 
#include <vector> 
using namespace std;

class ListNodeR{
    public:
        ListNodeR *next;
        int key;
        ListNodeR( int x) { key = x;next=NULL;}
};
void printListR(ListNodeR* l)
{
    ListNodeR* iter = l;
    while(iter != NULL)
    {
        cout << iter->key << "\t";
        iter = iter->next;
    }
    cout << endl;
}
// 把List反序
ListNodeR* ReverseList(ListNodeR* head)
{
    ListNodeR* iter = head;
    if(iter == NULL) return NULL;
    ListNodeR* tmp = NULL;
    ListNodeR* iter2 = iter->next;
    while( iter2!= NULL)
    {
        tmp = iter2->next;
        iter2->next = iter;
        iter = iter2;
        iter2 = tmp;
    }
    head->next = NULL;
    return iter;
}
class Solution_Review
{
    public:
        vector<int> addTwoNumbers(vector<int> left, vector<int> right)
        {}
        /*
         * 第一步：把left,right反序
         * 第二步：相加
         * 第三步：再反充
         * */
        ListNodeR* addTwoList(ListNodeR* left, ListNodeR* right)
        {
            ListNodeR* re_left = ReverseList(left);
            ListNodeR* re_right = ReverseList(right);
            int andOne = 0;
            int sum_tmp = 0;
            while(re_left->next != NULL && re_right->next != NULL)
            {
                sum_tmp = re_left->key + re_right->key + andOne;
                re_left->key = sum_tmp % 10;
                andOne = sum_tmp / 10;
                re_left = re_left->next;
                re_right = re_right->next;
            }
            printListR(re_left);
            printListR(re_right);
            if(re_left->next != NULL){
                while(re_left != NULL)
                {
                    sum_tmp = re_left->key + andOne;
                    re_left->key = sum_tmp % 10;
                    andOne = sum_tmp / 10;
                    re_left = re_left->next;
                }
                if(andOne > 0) re_left->next = new ListNodeR(andOne);
            }
            printListR(re_left);
            printListR(re_right);
            if(re_right->next != NULL)
            {
                while(re_right != NULL)
                {
                    sum_tmp = re_left->key + re_right->key + andOne;
                    re_left->key = sum_tmp % 10;
                    andOne = sum_tmp / 10;
                }
                if(andOne>0) re_left->next = new ListNodeR(andOne);
            }
            return ReverseList(re_left);
        }

};
