#include <iostream>
#include <limits>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int size = cards.size();
        if (size <= 1) {
            return -1;
        };
        std::unordered_map<int, int> lastIndex;  // 当前数字上一次出现的位置
        int minLen = std::numeric_limits<int>::max();
        bool found = false;
        for (int i = 0; i < size; i++) {
            int curr = cards[i];
            const auto iter = lastIndex.find(curr);
            if (iter != lastIndex.end()) {
                int len = i - iter->second;
                minLen = min(minLen, len);
                found = true;
            }
            lastIndex[curr] = i;
        }
        if (!found) {
            return -1;
        }
        return minLen + 1;
    }
};
