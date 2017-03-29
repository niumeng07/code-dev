#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& left, vector<int>& right) 
    {
        vector<int> all;
        int i = 0, j= 0;
        for( i = 0, j = 0; i<left.size() && j < right.size(); )
        {
            if(left[i] < right[j])
            {
                all.push_back(left[i]);
                i++;
            }
            else
            {
                all.push_back(right[j]);
                j++;
            }
        }
        for(; i<left.size(); i++)
            all.push_back(left[i]);
        for(; j<right.size(); j++)
            all.push_back(right[j]);

        if(all.size() % 2 == 1)
            return all[all.size()/2];
        else
            return (all[all.size()/2] + all[all.size() /2 -1 ]) /2.0 ;
    }
};
