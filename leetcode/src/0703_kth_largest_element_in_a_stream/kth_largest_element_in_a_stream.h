#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class KthLargest {
public:
  vector<int> nums;
  int k;
  KthLargest(int k, vector<int> &nums) {
    std::sort(nums.begin(), nums.end(), std::greater<int>());
    while (nums.size() > k) {
      nums.pop_back();
    }
    this->nums = nums;
    this->k = k;
    return;
  }

  int add(int val) {
    for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++) {
      if (val > *it) {
        nums.insert(it, val);
        break;
      }
    }
    if (nums.size() > k) {
      nums.pop_back();
    }
    return nums.back();
  }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
/*
 * Design a class to find the kth largest element in a stream. Note that it is
 * the kth largest element in the sorted order, not the kth distinct element.
 *
 * Your KthLargest class will have a constructor which accepts an integer k and
 * an integer array nums, which contains initial elements from the stream. For
 * each call to the method KthLargest.add, return the element representing the
 * kth largest element in the stream.
 * */
