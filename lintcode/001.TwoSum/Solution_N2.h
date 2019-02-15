#include <iostream>
#include <vector>
using namespace std;
/*
 * 不需要额外空间，时间复杂度高
 * */
class Solution_N2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int steps = 0;
        vector<int> out;                                      
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = nums.size() - 1 ; j>i; j--)
            {
                steps++;
                if((nums[i] + nums[j]) == target)
                {
                    out.push_back(i); 
                    out.push_back(j); 
                    break;
                }
            }
            if(!out.empty()) break;
        }
        cout << "steps: " << steps << std::endl;

        return out;
    }
};
