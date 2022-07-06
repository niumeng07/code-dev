#include <iostream>
#include <vector>
using namespace std;

/*
 * 给出非负整数数组 A,
 * 返回两个非重叠(连续)子数组中元素的最大和, 子数组的长度分别为 L 和 M.
 * (这里需要澄清的是, 长为 L 的子数组可以出现在长为 M 的子数组之前或之后. )
 * 从形式上看, 返回最大的 V
 * 而 V = (A[i] + A[i+1] + ... + A[i+L-1]) + (A[j] + A[j+1] + ... + A[j+M-1])
 * 并满足下列条件之一:
 * 0 <= i < i + L - 1 < j < j + M - 1 < A.length,
 * 或 0 <= j < j + M - 1 < i < i + L - 1 < A.length.
 */

class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        /* 方法一
         * 滑动窗口遍历firstLen子串的所有可能情况
         * 从剩余的left,right两段中搜索secondLen子串
         * */
        /* 方法二,动态规划
         * 找一个下标把数组分成两边,两个子数据各在其中一部分
         * */
        return 0;
    }
};
