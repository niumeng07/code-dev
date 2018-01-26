#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
/*
 * 给定vector<int> C, int target
 * 从C中找到所有和为target的组合
 * 思路：dfs搜索找到所有组合，若和为target则push
 * */

int sum_vector( vector<int> &vec)
{
    return accumulate(vec.begin() , vec.end(), 0);
}
void print_vec( vector<int>& vec)
{
    for(auto x : vec)
        cout << x << "\t";
    cout << endl;
}
void dfs(vector<int> &input, vector<vector<int> > &result, vector<int>& tmp, int target)
{
    if(target == 0)
    {
        result.push_back( std::move(tmp));
        return;
    }
    for( auto x : input)
    {
        int back = tmp.empty() ? 0 : tmp.back();
        if( target >= x && back <= x )
        {
            tmp.push_back(x);
            dfs( input, result, tmp, target - x);
            tmp.pop_back();
        }
    }
}
vector<vector<int> > dfs(vector<int> &input, int target)
{
    vector<int> tmp;
    vector<vector<int> > result;
    dfs(input, result, tmp, target);
    return result;
}
int main()
{
    vector<int> c({2,3,6,7});
    vector<vector<int> > result = dfs(c, 7);
    cout << "----------------------------------" << endl;
    for(auto vec : result)
        print_vec(vec);
}
