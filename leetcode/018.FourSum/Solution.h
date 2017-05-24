#include <vector>
#include <algorithm>
#include <iostream>
#include <time.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        return this->findNSum(nums, target, 4);
    }
    int sumVector(vector<int>& nums)
    {
        int sum = 0;
        for(int i = 0; i<nums.size(); i++)
            sum += nums[i];
        return sum;
    }

    bool clearElements()
    {
        this->result.erase(this->result.begin(), this->result.end());
        this->N = 0;
        this->target = 0;
        this->nums.erase(this->nums.begin(), this->nums.end());
        this->time.erase(this->time.begin(), this->time.end());
        this->time = vector<int>(10,0);
        this->max_i = 0;
        return true;
    }
    vector<vector<int> > findNSum(vector<int> &nums, int target, int N)
    {
        clearElements();
        sort(nums.begin(), nums.end());// 从小到大进行排序
        if( nums.size() < N )
            return result;

        vector<int> tmp;
        vector<int> pos;
        this->nums = nums;
        this->target = target;
        this->N = N;

        clock_t start, end;
        start = clock();
        findSum(tmp, pos);
        end = clock();
        this->time[0] = end - start;
        start = clock();
        for( int i = 0; i< this->result.size(); i++)
        {
            sort(this->result[i].begin(), this->result[i].end());
        }
        sort(this->result.begin(), this->result.end());
        this->result.erase(unique(this->result.begin(), this->result.end()), this->result.end());
        end = clock();
        this->time[1] = end - start;
        return this->result;
    }
    void findSum(vector<int> &tmp, vector<int> &pos)
    {
        clock_t start, end;
        if(tmp.size() == this->N && this->sumVector( tmp )== this->target)
        {
            this->result.push_back(tmp);
        }
        else if(tmp.size() < this->N )
        {
            for( int i = this->max_i; i < this->nums.size(); i++)
            {
                this->max_i = i + 1;
                tmp.push_back(nums[i]);
                pos.push_back(i);
                this->findSum(tmp, pos);
            }
        }
        tmp.pop_back();
        pos.pop_back();
        end = clock();
    }

public:
    int target;
    int N;
    vector<int> nums;
    vector<vector<int> > result;
    vector<int> time;
    int max_i = 0;
};
