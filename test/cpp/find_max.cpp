#include <iostream>
#include <string>
#include <vector>
using namespace std;

int FindMax(vector<int>& nums) {
  if (nums.size() == 1) return nums[0];
  if (nums.size() == 0) return 0;
  int start = 0;
  int end = nums.size() - 1;
  int mid = (end + start) / 2;
  int maxValue = nums[0];
  while (true) {         // 异常条件
    if (end <= start) {  // 终止条件
      maxValue = max(maxValue, nums[end]);
      break;
    } else if (end == start + 1) {
      maxValue = max(maxValue, max(nums[end], nums[start]));
      break;
    } else if (nums[mid] > nums[mid + 1]) {  // 处于下降区别  0,1,2   1<2不符合
      end = mid;                             // 搜索start到mid+1中间的所有值
      mid = (end + start) / 2;
    } else if (nums[mid] < nums[mid + 1]) {  // 处于上升区间
      start = mid;                           // 搜索mid到end之间的所有值
      mid = (end + start) / 2;
    } else {  // 两个数相等，那一定是最大值
      maxValue = nums[mid];
      break;
    }
  }
  return maxValue;
}
int main() {
  cout << "Hello world" << endl;
  vector<int> nums({1, 2, 3, 4, 5, 5, 4});
  cout << FindMax(nums) << endl;
  return 0;
}
