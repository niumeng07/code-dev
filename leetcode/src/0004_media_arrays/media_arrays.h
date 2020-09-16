/**
 * @brief
 *
 * there two sorted arrays nums1 and nums2 of size m and n respectively.
 *
 * Find the median of the two sorted arrays. The overall run time complexity
 * should be O(log (m+n)).
 *
 * Example 1:
 * nums1 = [1, 3]
 * nums2 = [2]
 * The median is 2.0
 *
 * Example 2:
 * nums1 = [1, 2]
 * nums2 = [3, 4]
 * The median is (2 + 3)/2 = 2.5
 *
 */
#include <iostream>
#include <vector>
using namespace std;
class MediaArrays {
public:
    double findMedianSortedArrays(vector<int> &left, vector<int> &right) {
        vector<int> all;
        int i = 0, j = 0;
        for (i = 0, j = 0; i < left.size() && j < right.size();) {
            if (left[i] < right[j]) {
                all.push_back(left[i]);
                i++;
            } else {
                all.push_back(right[j]);
                j++;
            }
        }
        for (; i < left.size(); i++) all.push_back(left[i]);
        for (; j < right.size(); j++) all.push_back(right[j]);

        if (all.size() % 2 == 1)
            return all[all.size() / 2];
        else
            return (all[all.size() / 2] + all[all.size() / 2 - 1]) / 2.0;
    }
};
