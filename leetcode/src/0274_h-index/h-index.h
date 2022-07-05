#include <iostream>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        std::sort(citations.begin(), citations.end());
        int h = 0;
        for (int i = citations.size() - 1; i >= 0; --i) {
            if (citations[i] >= h + 1) {
                h++;
            }
        }
        return h;
    }
};
