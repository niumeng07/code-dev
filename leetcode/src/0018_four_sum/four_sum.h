#include <vector>
#include <algorithm>
#include <iostream>
#include <time.h>
using namespace std;
class FourSum {
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
        clearElements();
        sort(nums.begin(), nums.end());// 从小到大进行排序
        if( nums.size() < N )
            return result;

        vector<int> tmp;
        this->nums = nums;
        this->target = target;
        this->N = N;

        findSum(tmp);
        for( int i = 0; i< this->result.size(); ++i)
        {
            sort(this->result[i].begin(), this->result[i].end());
        }
        sort(this->result.begin(), this->result.end());
        this->result.erase(unique(this->result.begin(), this->result.end()), this->result.end());
        return this->result;
    }
    void findSum(vector<int> &tmp)
    {
        if(tmp.size() == this->N && this->sumTmp== this->target)
        {
            this->result.push_back(tmp);
        }
        else if(tmp.size() < this->N )
        {
            for( int i = this->max_i; i < this->nums.size(); ++i)
            {
                int _need = this->N - tmp.size();// 还需要几个数
                int _tmp = this->sumTmp;
                for(int j = 0; j < _need && i + j < nums.size(); j++)
                    _tmp += nums[i + j];
                if(this->sumTmp >= this->target && nums[i] > 0)
                    break;
                if( _tmp > this->target)
                    break;
                else
                {
                    this->max_i = i + 1;
                    tmp.push_back(nums[i]); // 导致超时
                    this->sumTmp += nums[i];// 导致超时
                    this->findSum(tmp);
                    this->sumTmp -= tmp.back();
                    tmp.pop_back();
                }
            }
        }
    }

public:
    int target;
    int N;
    vector<int> nums;
    vector<vector<int> > result;
    vector<int> last;
    vector<int> time;
    int max_i = 0;
    int sumTmp = 0;
};
