#include "header.h"

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int k = nums1.size() - 1; // 将要放数的地方
        int i = m - 1;  // 可能要取数的地方
        int j = n - 1;  // 可能要取数的地方
        while (i >= 0 && j >= 0) {
            if (nums1[i] >= nums2[j]) {
                nums1[k] = nums1[i];
                k--;
                i--;
            } else {
                nums1[k] = nums2[j];
                k--;
                j--;
            }
        }
        while (j >= 0) {
            nums1[k] = nums2[j];
            k--;
            j--;
        }
        // while (i >= 0) {

        // }
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    vector<int> nums1 = {1,2,3, 0, 0, 0};
    vector<int> nums2 = {2,3,4};

    nums1 = {0};
    nums2 = {2};
    solution.merge(nums1, 0, nums2, 1);

    return 0;
}
