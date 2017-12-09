#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

void dfs(vector<int>& nums, vector<vector<int> > &result, vector<int> &tmp, int index)
{
    for(int i = index; i < nums.size(); i++ )
    {
        tmp.push_back(nums[i]);
        result.push_back(tmp);
        dfs(nums, result, tmp, i + 1);
        tmp.pop_back();
    }
}
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > results;
        vector<int> tmp;
        results.push_back(tmp);
        dfs(nums, results, tmp, 0);
        //results.erase( unique(results.begin(), results.end() ), results.end() );
        return results;
    }
};
