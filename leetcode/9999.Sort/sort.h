#ifndef __LD__SORT__H__
#define __LD__SORT__H__

#include <vector>
#include <iostream>
using namespace std;
class ld_sort{
public:
    int spm(vector<int> &nums, int left, int right, int middle)
    {
        int i = 0, j = nums.size() - 1;
        while( i < middle && j > middle)
        {
            if(nums[i] > nums[middle] && nums[j] < nums[middle])
            {
                swap(nums[i], nums[j]);
                i++;
                j--;
            }
            else if(nums[i] >nums[middle])
                j--;
            else
                i++;
        }
        while(i < middle)
        {
            if(nums[i] > nums[middle])
            {
                swap(nums[middle], nums[middle - 1]);
                swap(nums[i], nums[middle]);
                i++;
                middle--;
            }
            else
                i++;
        }
        while(j > middle)
        {
            if(nums[j] < nums[middle])
            {
                swap(nums[middle], nums[middle + 1]);
                swap(nums[j], nums[middle]);
                j--;
                middle++;
            }
            else
                j--;
        }
        return middle;
    }
    void quickSort(vector<int> &nums)
    {
        int left = 0;
        int right = nums.size() - 1;
        int middle = (left + right ) /2;
        qs(nums, left, right, middle);
    }
    void qs(vector<int> &nums, int left, int right, int middle)
    {
        int e = spm(nums, left, right, middle );        
        if( left < e)
            qs(nums, left, e, (e+left)/2);
        if( e + 1 < right)
            qs(nums, e + 1, right, (e+right)/2);
    }
};
#endif
