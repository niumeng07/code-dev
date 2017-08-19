#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void dfs(vector<vector<int> > &result, vector<int> &tmp, vector<int> &nums, int start)
{
    if(start == nums.size())
        return;
    for(int j = start; j<nums.size();j++){
        tmp.push_back(nums[j]);
        if( find(result.begin(), result.end(), tmp ) == result.end() )
            result.push_back(tmp);
        dfs(result, tmp, nums, j + 1);
        tmp.pop_back();
    }
}
class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end() );
        vector<vector<int> > result;
        vector<int> tmp;
        dfs(result, tmp, nums, 0);
        result.push_back({});
        return result;
    }
};
