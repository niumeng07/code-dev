#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
void printVector(vector<int> input){
    for( auto x:input)
        cout << x << " ";
    cout << endl;
}
class Solution_B{
public:
    vector<int> twoSum(vector<int> &input, int target){
        vector<int> result;
        sort(input.begin(), input.end());
        vector<int> need;
        for(int i = 0; i < input.size(); i++)
            need.push_back( target - input[i]);
        for(int i = 0, j = input.size() - 1; i < need.size();){
            if( need[i] > input[j] ) i++;
            if( need[i] == input[j]){
                result.push_back(input[i]); 
                result.push_back(input[j]);
                break;
            }
            if( need[i] < input[j]) j--;
            if( j < i) break;
        }
        return result;
    }
};
class Solution_C{
public:
    vector<int> twoSum(vector<int> &input, int target){
        vector<int> result;
        unordered_map<int,int> hash;
        for(int i = 0; i<input.size(); i++){
            hash[i] = target - input[i];
        }
        for( int i = 0; i<input.size(); i++){
            if(hash.find(input[i]) != hash.end()){
                result.push_back(input[i]);
                result.push_back(hash[i]);
                break;
            }
        }
        return result;
    }
};
