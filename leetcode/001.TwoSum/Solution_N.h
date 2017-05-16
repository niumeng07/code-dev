#include <vector>
#include <unordered_map>
using namespace std;

class Solution_N {
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        unordered_map<int, int> hash;
        vector<int> result;
        for (int i = 0; i < numbers.size(); i++) 
        {
            int numberToFind = target - numbers[i];

            if (hash.find(numberToFind) != hash.end()) 
            {
                result.push_back(hash[numberToFind] + 1);
                result.push_back(i + 1);            
                return result;
            }
            hash[numbers[i]] = i;
        }
        return result;
    } 
};
