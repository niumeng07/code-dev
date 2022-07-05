#include <iostream>
using namespace std;

class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[0] < b[0];
    }

public:
    // 第一想法:先按下界排序,排序后检测的上下界是否重合
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> results;
        std::sort(intervals.begin(), intervals.end(), cmp);
        for (int i = 0; i < intervals.size();) {
            int start = intervals[i][0];
            int end = intervals[i][1];
            int j = i + 1;
            while (j < intervals.size() && intervals[j][0] <= end) {
                if (intervals[j][1] > end) {
                    end = intervals[j][1];
                }
                j++;
            }
            i = j;
            results.push_back(vector<int>({start, end}));
        }
        return results;
    }
};
