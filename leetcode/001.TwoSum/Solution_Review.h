#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution_Review {
    public:
        vector<int> towSum(vector<int>& nums, int target){
            vector<int> result;
            unordered_map<int,int> hashmap;
            for (int i = 0; i < nums.size(); i++) 
            {
                if(hashmap.find(target - nums[i]) != hashmap.end())
                {
                    result.push_back(nums[i]);
                    result.push_back(target-nums[i]);
                    return result;
                }
                hashmap[nums[i]] = i;
            }
            return result;
        }
        vector<vector<int> > twoSumAll(vector<int>& nums, int target)
        {
            vector<vector<int> > result;
            vector<int> tmp;
            unordered_map<int, int> hashmap;

            for(int i = 0; i < nums.size(); i++)
            {
                if(hashmap.find(target-nums[i]) != hashmap.end())
                {
                    tmp.clear();
                    tmp.push_back(nums[i]);
                    tmp.push_back(target - nums[i]);
                    result.push_back(std::move(tmp));
                }
                hashmap[nums[i]] = i;
            }
            return result;
        }
};
