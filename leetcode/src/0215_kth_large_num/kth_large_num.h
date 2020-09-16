#include <iostream>
#include <vector>
using namespace std;

void printVec(vector<int>& nums) {
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
}
class KthLargeNum {
public:
    int findKthLargest(vector<int>& nums, int k) {
        vector<int> tmp;
        for (int i = 0; i < nums.size(); i++) {
            if (tmp.size() < k) {
                tmp.push_back(nums[i]);
            } else {
                int j = 0;
                for (int k = 1; k < tmp.size(); k++) {
                    if (tmp[k] < tmp[j]) j = k;
                }
                if (nums[i] > tmp[j]) tmp[j] = nums[i];
            }
        }
        int small = tmp[0];
        for (int i = 1; i < tmp.size(); i++) {
            if (tmp[i] < small) small = tmp[i];
        }
        return small;
    }
    int findKthLargest2(vector<int>& nums, int k) {
        int s = 0, j = 0, i = 0;
        for (i = k; i < nums.size(); i++) {
            s = 0;
            for (j = 1; j < k; j++) {
                if (nums[j] < nums[s]) s = j;
            }
            if (nums[i] > nums[s]) nums[s] = nums[i];
        }
        j = 0;
        for (i = 1; i < k; i++) {
            if (nums[i] < nums[j]) j = i;
        }
        return nums[j];
    }
};
