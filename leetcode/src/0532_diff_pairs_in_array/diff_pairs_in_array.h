#include <vector>
#include <iostream>
#include <set>
#include <list>

using namespace std;

class DiffPairsInArray {
public:
    set<set<int> > store;
    set<int> temp;
    int findPairs(vector<int>& nums, int k) {
        if (k < 0) {
            return 0;
        }
        store.clear();
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                temp.clear();
                if(nums[i] - nums[j] == k) {
                    temp.insert(nums[i]);
                    temp.insert(nums[j]);
                    store.insert(temp);
                } else if (nums[i] - nums[j] == 0 - k) {
                    temp.insert(nums[j]);
                    temp.insert(nums[i]);
                    store.insert(temp);
                }
            }
        }
        return store.size();
    }
};
