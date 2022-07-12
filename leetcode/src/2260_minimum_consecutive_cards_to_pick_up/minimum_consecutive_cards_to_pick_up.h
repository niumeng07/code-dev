#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int size = cards.size();
        if (size <= 1) {
            return -1
        };
        vector<int> dp(size, 0);      // 起始位置
        vector<int> dpLen(size, -1);  // 长度
        for (int i = 0; i < size; i++) {
            
        }
    }
};
