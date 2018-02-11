#include <vector>
#include <iostream>
using namespace std;
/* 1 1 1 3 3 3 6 6 6 7 */
class Solution {
public:
    int singleNumber0(vector<int>& nums){
        int length = nums.size();
        int result = 0;
        for(int i = 0; i < 32; i++){//对每一个二进制位进行遍历
            int count = 0;
            int mask = 1 << i;
            for(int j = 0; j < length; j++){//每一个数的第i位进行检测
                if(mask & nums[j]){
                    count++;
                }
            }
            if(count % 3 == 1 )
                result = result |mask;
        }
        return result;
    }
    int singleNumber(vector<int>& nums) {
		int length = nums.size();  
        int result = 0;  
        for(int i = 0; i<32; i++){  
            int count = 0;   
            int mask = 1<< i;  
            for(int j=0; j<length; j++){  
                if(nums[j] & mask)  
                    count++;  
            }  
          if(count %3)  
              result |= mask;  
        }  
        return result;  
    }
	int singleNumber2(vector<int>& nums) {
        int counterOne = 0;
        int counterTwo = 0;
        for (int i = 0; i < nums.size(); i++){
            counterOne = (~counterTwo) & (counterOne ^ nums[i]);
            counterTwo = (~counterOne) & (counterTwo ^ nums[i]);
        }
        return counterOne;
    }
};
int main(){
    vector<int> input({1,1,1,2,3,3,3,4,4,4});
    Solution su;
    cout << su.singleNumber0(input) << endl;
    cout << su.singleNumber(input) << endl;
	cout << su.singleNumber2(input) << endl;
}
