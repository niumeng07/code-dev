#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int> > res;
        do{
            res.push_back(nums);
        }while(next_permutation(res.begin(), res.end()));
        return res;
    }
};
