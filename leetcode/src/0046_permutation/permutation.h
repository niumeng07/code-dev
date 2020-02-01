#include <vector>
#include <algorithm>
using namespace std;
class Permutation {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > res;
        sort(nums.begin(), nums.end());
        do{
            res.push_back(nums);
        }while(std::next_permutation(nums.begin(), nums.end()));
        return res;
    }
};
