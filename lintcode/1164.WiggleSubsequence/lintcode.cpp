#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        /**
         * @param nums: the given sequence
         * @return: the length of the longest subsequence that is a wiggle sequence
         */
        bool is_wiggle_k(int k, vector<int> &nums) {
            if(k==0) return true;
            if(k==1 && nums[1] != nums[0]) return true;
            if(k==1 && nums[1] == nums[0]) return false;
            if((nums[k]-nums[k-1])*(nums[k-1]-nums[k-2])<0) return true;
            return false;
        }
        int wiggleMaxLength(vector<int> &nums) {
            // Write your code here
            if(nums.size() == 0) return 0;
            int cur_max = 1;
            int max = 1;
            int begin = 0;
            int i = 0;
            for(i = 1; i < nums.size(); i++) {
                if(is_wiggle_k(i, nums)) {
                    cur_max = i - begin +1;
                } else {
                    max = cur_max > max ? cur_max : max;
                    if(nums[i] == nums[i-1]) { cur_max = 1; begin = i;}
                    else {cur_max = 2; begin = i-1;}
                }
            }
            if(i==nums.size()) max = cur_max > max ? cur_max : max;
            return max;
        }
};
int main(int argc, char *argv[])
{
    Solution su;
    //             b   i
    vector<int> x;
    x = {1};
    x = {3,3,3,2,5};
    x = {1,2,3,4,5,6,7,8,9};
    x = {1,2,1,2,1};
    x = {};
    x = {1,1};
    x = {1,17,5,10,13,15,10,5,16,8};
    cout << "+++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << su.wiggleMaxLength(x) << endl;
    cout << "-------------------------------------------" << endl;
    return 0;
}
