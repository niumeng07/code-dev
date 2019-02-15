#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> twoSum( vector<int> &nums, int target)
    {
        vector<int> result;
        unordered_map<int, int> hash;
        for(int i = 0; i< nums.size(); i++)
        {
            int numToFind = target - nums[i];
            if ( hash.find(numToFind) != hash.end() )
            {
                result.push_back(i);
                result.push_back(hash[numToFind]);
            }
            hash[nums[i] ] = i;
        }
        return result; 
    }
};

int main()
{
    Solution su;
    vector<int> vec({1,2,3,4,8,9,10,-1});
    vector<int> result = su.twoSum(vec, 0);
    for(auto x:result)
        cout << x << ends;
    cout << endl;
}
