#include <vector>
#include <iostream>
using namespace std;
class Solution_B {
public:
    /*
     * left, right 是 sorted 数组，这样可以直接维护 4 个指针
     * 或者合并起来
     * 用指针的方式应该更快速
     * */
    double findMedianSortedArrays(vector<int>& left, vector<int>& right) 
    {
        int l_start = 0, l_end = left.size(), r_start = 0, r_end = right.size();
    }
};
