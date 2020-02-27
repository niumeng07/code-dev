/**
 * @file container_most_water.h
 * @author myliuda@sina.com
 * @version 0.0.0
 * @date 2020-02-04
 * @brief
 *   Given n non-negative integers a1, a2, ..., an, where each represents a
 * point at coordinate (i, ai). n vertical lines are drawn such that the two
 * endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together
 * with x-axis forms a container, such that the container contains the most
 * water.
 * Note: You may not slant the container and n is at least 2.
 *    * 给定 N 个非负数，a1,a2,...an
 *    * 每个数表示一个点(i,ai)在坐标系中表示一个位置
 *    * 画 n 条垂直的线，第 i 条线的终点为(i,ai)和(i,0)
 *    * 从这些线中，找到两条线，加上 x 轴共三条线组成最大的水桶
 */
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class ContainerMostWater {
public:
  // 两层循环超时
  int maxArea1(vector<int> &height) {
    int max = 0;
    for (int i = 0; i < height.size(); i++) {
      for (int j = height.size() - 1; j > i; j--) {
        int curr = ((j - i) * min(height[i], height[j]));
        max = (curr > max) ? curr : max;
      }
    }
    return max;
  }

  int maxArea(vector<int> &height) {
    int left = 0, right = height.size() - 1, m = 0, h = 0;
    bool t = true;
    while (left < right) {
      if (height[left] <= height[right]) {
        h = height[left];
        t = true;
        m = m > (right - left) * h ? m : (right - left) * h;
        left++;
      } else {
        h = height[right];
        t = false;
        m = m > (right - left) * h ? m : (right - left) * h;
        right--;
      }
    }
    return m;
  }

  int maxAreaReview(vector<int> &height) {
    int left = 0, right = height.size() - 1;
    int m = (right - left) * min(height[right], height[left]);
    int m2;
    while (left < right) {
      m2 = (right - 1 - left) * min(height[right - 1], height[left]) >
                   (right - left - 1) * min(height[right], height[left + 1])
               ? (right - 1 - left) * min(height[right - 1], height[left])
               : (right - left - 1) * min(height[right], height[left + 1]);
      m = m2 > m ? m2 : m;
    }
    return 0;
  }
};
