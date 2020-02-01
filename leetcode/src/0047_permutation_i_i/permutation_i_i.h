#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

class PermutationII {
public:
    void insertRes( vector<int> &pos, vector<int> &nums, vector<vector<int> > &res)
    {
        for(int i = 0; i<nums.size(); i++)
        {
            tmp[i] = nums[pos[i]];
        }
        rset.insert(tmp);
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        tmp.resize(nums.size(), 0);
        vector<int> position(nums.size(), 0);
        for(int i = 0; i < nums.size(); i++)
            position[i] = i;
        do{
            this->insertRes(position, nums, res);
        }while(std::next_permutation(position.begin(), position.end()));
        res = vector<vector<int> >(rset.begin(), rset.end());
        return res;
    }
    vector<vector<int> > res;
    set<vector<int> > rset;
    vector<int> tmp;
};
