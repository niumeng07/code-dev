#include <iostream>
#include <vector>

using namespace std;

class ListNode {
public:
  int value;
  ListNode* next;
  ListNode(int v) { value = v; }
};

ListNode* buildList(vector<int>& nums) {
  if (nums.size() == 0) return nullptr;
  ListNode* head = new ListNode(nums[0]);
  ListNode* iter = head;
  for (int i = 1; i < nums.size(); i++) {
    iter->next = new ListNode(nums[i]);
    iter = iter->next;
  }
  return head;
}

void printList(ListNode* head) {
  ListNode* iter = head;
  while (iter) {
    cout << iter->value << ", ";
    iter = iter->next;
  }
  cout << endl;
}

ListNode* reverseList(ListNode* head) {
  if (head == nullptr) return head;
  ListNode* curr = head;
  ListNode* pre = nullptr;
  while (curr) {
    ListNode* next = curr->next;  // 相当于缓存变量
    curr->next = pre;

    pre = curr;
    curr = next;
  }
  return pre;
}

ListNode* reverseListBy2(ListNode* head) {
  ListNode* dummyHead = new ListNode(0);  // 新建了一个字段后面再删除了
  dummyHead->next = head;
  ListNode* temp = dummyHead;
  // temp, node1, node2
  while (temp->next != nullptr && temp->next->next != nullptr) {
    ListNode* node1 = temp->next;
    ListNode* node2 = temp->next->next;
    temp->next = node2;
    node1->next = node2->next;
    node2->next = node1;
    temp = node1;
  }
  return dummyHead->next;
}

vector<ListNode*> reverseListPart(ListNode* start, ListNode* end) {
  ListNode* prev = end->next;
  ListNode* p = start;
  while (prev != end) {
      ListNode* nex = p->next;
      p->next = prev;
      prev = p;
      p = nex;
  }
  ListNode* temp = start;
  start = end;
  end = temp;
  // cout << "part新的start:" << start->value << ", 新的end:" << end->value << endl;
  return vector<ListNode*>({start, end});
}

ListNode* reverseListByK(ListNode* head, int k) {
  ListNode* dum = new ListNode(0);
  dum->next = head;
  ListNode* start = nullptr;
  ListNode* end = dum;
  k--;
  while (end->next != nullptr) {
    // 重新较正start, end
    ListNode* pre = end;
    start = end->next;
    end = start;

    int i = 0;  // 数个数k个
    while (i < k && end->next != nullptr) {
      end = end->next;
      i++;
    }
    if (i < k) {   // 不足k个,不操作(也可以操作)
      break;
    }
    ListNode* next = end->next;
    // 把start到end的反转,返回新的start和end
    auto startendnew = reverseListPart(start, end);
    start = startendnew[0];
    end = startendnew[1];
    // pre->next = 新的start
    pre->next = start;
    // 新的end->next = next;
    end->next = next;
  }
  return dum->next;
}

int main(int argc, char* argv[]) {
  vector<int> nums({1, 2, 3, 4, 5, 6, 7});
  ListNode* head = buildList(nums);
  printList(head);
  ListNode* head2 = reverseListByK(head, 3);
  printList(head2);
  return 0;
}
