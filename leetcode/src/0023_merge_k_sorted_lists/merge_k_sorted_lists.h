/* You are given an array of k linked-lists lists, each linked-list is sorted in
 * ascending order. Merge all the linked-lists into one sorted linked-list and
 * return it.
 *
 * Example 1:
 *   Input: lists = [[1,4,5],[1,3,4],[2,6]]
 *   Output: [1,1,2,3,4,4,5,6]
 *   Explanation: The linked-lists are:
 *   [
 *     1->4->5,
 *     1->3->4,
 *     2->6
 *   ]
 *   merging them into one sorted list:
 *   1->1->2->3->4->4->5->6
 *
 * Example 2:
 *   Input: lists = []
 *   Output: []
 *
 *   Example 3:
 *   Input: lists = [[]]
 *   Output: []
 *
 * Constraints:
 *   k == lists.length
 *   0 <= k <= 10^4
 *   0 <= lists[i].length <= 500
 *   -10^4 <= lists[i][j] <= 10^4
 *   lists[i] is sorted in ascending order.
 *   The sum of lists[i].length won't exceed 10^4.
 * */
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

bool cmp(const ListNode* lhs, const ListNode* rhs) {
    return lhs->val < rhs->val;
}
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<ListNode*> iters;
        for (int i = 0; i < lists.size(); ++i) {
            if (lists[i] != nullptr) iters.push_back(lists[i]);
        }
        sort(iters.begin(), iters.end(), cmp);

        ListNode* res = new ListNode();
        ListNode* iter = res;
        ListNode* tmp = nullptr;
        while (iters.size()) {
            iter->next = iters[0];
            iter = iter->next;
            if (iters[0]->next != nullptr) {
                iters[0] = iters[0]->next;
            } else {
                iters.erase(iters.begin());
            }
            for (int i = 1, j = 0; i < iters.size();) { // 可以改成归并的依次合并2个List,可能省掉这个for循环
                if (iters[i]->val < iters[j]->val) {
                    tmp = iters[i];
                    iters[i] = iters[j];
                    iters[j] = tmp;
                    j = i;
                    i++;
                } else {
                    break;
                }
            }

            iter->next = nullptr;
        }
        return res->next;
    }
};

