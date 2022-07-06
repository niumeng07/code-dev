#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        if (cardPoints.size() <= k) {
            return accumulate(cardPoints.begin(), cardPoints.end(), 0);
        }
        int left = 0;
        int right = accumulate(cardPoints.end() - k, cardPoints.end(), 0);
        int right_start = cardPoints.size() - k;
        int maxScore = left + right;
        int tmp = 0;
        for (int i = 0; i < k; i++) {
            left += cardPoints[i];
            right -= cardPoints[right_start];
            tmp = left + right;
            if (tmp > maxScore) {
                maxScore = tmp;
            }
            right_start++;
        }
        return maxScore;
    }
};
