#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
    int hIndex(vector<int>& citations) {
        if( citations.size() == 0)
            return 0;
        sort(citations.begin(),citations.end());
        for(int i=0;i<citations.size();i++)
        {
            if(citations[i]>=citations.size()-i) 
                return citations.size()-i;
        }
        /*
        int start = 0, end = citations.size() - 1;
        int middle;
        while(end - start > 1)
        {
            middle = (start + end)/2;
            if(citations[middle] < citations.size()-middle) 
                start = middle;
            else
                end = middle;
        }
        if(citations[start]>=citations.size()-start)
            return citations.size()-start;
        else if ( citations[end] >= citations.size() -end)
            return citations.size() - end;
        */
        return 0;
    }
};
