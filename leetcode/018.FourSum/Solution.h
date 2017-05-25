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

    bool clearElements()
    {
        this->result.erase(this->result.begin(), this->result.end());
        this->N = 0;
        this->target = 0;
        this->nums.erase(this->nums.begin(), this->nums.end());
        this->time.erase(this->time.begin(), this->time.end());
        this->time = vector<int>(10,0);
        this->max_i = 0;
        this->sumTmp = 0;
        return true;
    }
    vector<vector<int> > findNSum(vector<int> &nums, int target, int N)
    {
        clock_t start, end;
        start = clock();
        clearElements();
        end = clock();
        cout << "time clearElement: " << end - start << endl;
        start = clock();
        sort(nums.begin(), nums.end());// 从小到大进行排序
        end = clock();
        cout << "time sort nums: " << end - start << endl;
        if( nums.size() < N )
            return result;

        start = clock();
        vector<int> tmp;
        this->nums = nums;
        this->target = target;
        this->N = N;
        end = clock();
        cout << "time init class Element: " << end - start << endl;

        start = clock();
        findSum(tmp);
        end = clock();
        cout << "time findSum: " << end - start << endl;
        start = clock();
        for( int i = 0; i< this->result.size(); i++)
        {
            sort(this->result[i].begin(), this->result[i].end());
        }
        sort(this->result.begin(), this->result.end());
        this->result.erase(unique(this->result.begin(), this->result.end()), this->result.end());
        end = clock();
        cout << "time sort result: " << end -start << endl;
        for ( auto x : this->time)
            cout << x << "  " << ends;
        cout << endl;
        return this->result;
    }
    void findSum(vector<int> &tmp)
    {
        clock_t start, end;
        if(tmp.size() == this->N && this->sumTmp== this->target)
        {
            start = clock();
            this->result.push_back(tmp);
            end = clock();
            this->time[0] += (end -start);
        }
        else if(tmp.size() < this->N )
        {
            for( int i = this->max_i; i < this->nums.size(); i++)
            {
                if(!(this->sumTmp >= this->target && nums[i] > 0))
                {
                    this->max_i = i + 1;
                    start = clock();
                    tmp.push_back(nums[i]); // 导致超时
                    end = clock();
                    this->time[1] += (end -start);
                    start = clock();
                    this->sumTmp += nums[i];// 导致超时
                    end = clock();
                    this->time[2] += (end -start);
                    this->findSum(tmp);
                }
            }
        }
        this->sumTmp -= tmp.back();
        tmp.pop_back();
        end = clock();
    }

public:
    int target;
    int N;
    vector<int> nums;
    vector<vector<int> > result;
    vector<int> time;
    int max_i = 0;
    int sumTmp = 0;
};
