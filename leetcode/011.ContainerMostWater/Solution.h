#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    /* 两层循环超时 */
    int maxArea1(vector<int>& height) {
        int max = 0;
        for(int i = 0; i < height.size(); i++)
        {
            for(int j = height.size() - 1; j > i; j--)
            {
                int curr = ( (j - i ) * min( height[i], height[j]));
                max = ( curr > max ) ? curr : max;
            }
        }
        return max;
    }
    /* 有没有一层特征解决的方案 */
    /* 414*/
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int m = 0;
        int h = 0;
        bool t = true;
        while(left < right)
        {
            if( height[left] <= height[right])
            {
                h = height[left];
                t = true;
            }
            else
            {
                h = height[right];
                t = false;
            }
            
            m = std::max( m, (right - left) * h);
            if( t )
                left++;
            else
                right--;
        }
        return m;
    }
};
