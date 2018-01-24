#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
       int i = 0, j = 0;
       int size = nums.size();
       while( i < size && j < size){
           if(nums[i] == 0){
               j = i+1;
               while(nums[j] == 0 && j < size)
                   j++;
               if(j >= size)
                   break;
               nums[i] = nums[j];
               nums[j] = 0;
           }
           i++;
       }
       for(int k = i + 1; k < size; k++)
           nums[k] = 0;
    }
};
void printVector(vector<int> &a){
    for(auto x : a)
        cout << x << "\t";
    cout << endl;
}
int main(){
    vector<int> input({1,2,0,3,4,0,0,5,6,7,0,0,0});
    vector<int> input2({});
    vector<int> input3({0});
    vector<int> input4({0,4});
    vector<int> input5({4});
    Solution su;
    su.moveZeroes(input);
    su.moveZeroes(input2);
    su.moveZeroes(input3);
    su.moveZeroes(input4);
    su.moveZeroes(input5);
    printVector(input);
    printVector(input2);
    printVector(input3);
    printVector(input4);
    printVector(input5);
}
