#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class ContainerMostWater {
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
	int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1, m = 0, h = 0;
        bool t = true;
        while(left < right) {
            if( height[left] <= height[right]) {
                h = height[left];
                t = true;
                m = m > (right - left) * h ? m : (right - left) * h;
                left++;
            }
            else {
                h = height[right];
                t = false;
                m = m > (right - left) * h ? m : (right - left) * h;
                right--;
            }
        }
        return m;
    }
};
