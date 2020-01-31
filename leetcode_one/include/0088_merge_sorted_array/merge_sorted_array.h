#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution2 {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for( auto x : nums2)
            nums1.push_back(x);

        sort(nums1.begin(), nums1.end());
    }
};
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, tar = m + n - 1;
        while (j >= 0) {
            nums1[tar--] = i >= 0 && nums1[i] > nums2[j] ? nums1[i--] : nums2[j--];
        }
    }
};
