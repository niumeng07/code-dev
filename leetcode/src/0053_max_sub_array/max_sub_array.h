#include <vector>
using namespace std;
class MaxSubArray {
public:
    int process(vector<int>& nums, int curr_pos)
    {
        if(curr_pos == nums.size())
            return 0;
        if(nums[curr_pos] > 0)
            m = (nums[curr_pos] + process(nums, curr_pos+1)) > m ? 
                (nums[curr_pos] + process(nums, curr_pos+1)) : m;
        else
            m = process(nums, curr_pos+1) > m ?
                process(nums, curr_pos+1) : m;
        return m;
    }
    int maxSubArray(vector<int>& nums) {
        return process(nums, 0);
    }
public:
    int m = 0;
};
