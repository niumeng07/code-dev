#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class MinTimeDiff
{
public:
    static bool compare_m(const int& a, const int& b) {return a < b;}
    int findMinDifference(vector<string>& timePoints) 
    {
        if( timePoints.size() < 2) return 0;
        std::vector<int> minute;
        for ( int i = 0; i< timePoints.size(); i++)
        {
            string l = timePoints[i];
            int minu = ( ( char(l[0]) - '0') * 10 + ( char(l[1]) - '0' ) ) * 60 + ( ( char(l[3]) - '0' ) * 10 + char(l[4]) - '0' );
            minute.push_back(minu);
        }
        sort(minute.begin(), minute.end(), compare_m);
        int right = minute[0] > minute[minute.size() -1 ] ? minute[0] : minute[minute.size() -1 ];
        int left = minute[0] < minute[minute.size() -1 ] ? minute[0] : minute[minute.size() -1 ];
        int min_x = (right - left < left + 24*60 - right ) ? right - left : left + 24*60 - right;
        for(int i = 0; i + 1 < minute.size(); i++)
        {
            int right = minute[i] > minute[i + 1] ? minute[i]: minute[i + 1];
            int left = minute[i] < minute[i + 1] ? minute[i]: minute[i + 1];
            min_x = ( ((right - left < left + 2400 - right ) ? right - left : left + 2400 - right )  < min_x ) ? ((right - left < left + 2400 - right ) ? right - left : left + 2400 - right ) : min_x;
        }
        return min_x;
    }
};
