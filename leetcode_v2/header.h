#include <algorithm>
#include <iostream>
#include <numeric>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class ListNode {
public:
    int value;
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class TreeNode {
public:
    int value;
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

template <class T>
void print_vector(const vector<T>& nums) {
    for (const auto& item : nums) {
        cout << item << " ";
    }
    cout << endl;
}

template <class T>
void print_matrix(const vector<vector<T>>& matrix) {
    for (const auto& vec : matrix) {
        print_vector(vec);
    }
}

void print_list(ListNode* head) {
    ListNode* iter = head;
    while (iter != nullptr) {
        cout << iter->val << " ";
        iter = iter->next;
    }
    cout << endl;
}
