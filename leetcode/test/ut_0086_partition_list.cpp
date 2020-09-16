#include <vector>

#include "0086_partition_list/partition_list.h"
#include "gtest/gtest.h"
using namespace std;

ListNode* createList(std::vector<int> input) {
    int index = 0;
    ListNode* head = new ListNode(input[index++]);
    ListNode* iter = head;
    for (; index < input.size(); index++) {
        iter->next = new ListNode(input[index]);
        iter = iter->next;
    }
    return head;
}
void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}
int main(int argc, char** argv) {
    PartitionList su;
    ListNode* head = createList(vector<int>({1, 4, 3, 2, 5, 2}));
    printList(head);
    ListNode* result = su.partition(head, 3);
    printList(result);
}
