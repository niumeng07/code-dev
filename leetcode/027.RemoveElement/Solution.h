#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        for( auto iter = nums.begin(); iter != nums.end(); )
        {
            if( *iter == val )
                nums.erase(iter);
            else
                iter++;
        }
        return nums.size();
    }
};
