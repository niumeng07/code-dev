#include <vector>
#include <algorithm>
using namespace std;

class CombinationSum {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        std::vector< vector<int> > result;
        std::vector<int> comb;

        backTrack( result, comb, candidates, target);
        return result;
    }

    void backTrack( vector<vector<int> > &res, vector<int> comb, vector<int> &cand, int target)
    {
        if(target == 0)
        {
            res.push_back( std::move(comb));
            return;
        }
        for( auto x : cand)
        {
            int back = comb.empty() ? 0 : comb.back();
            if( target >= x && back <= x )
            {
                comb.push_back(x);
                backTrack( res, comb, cand, target - x);
                comb.pop_back();
            }
        }
    }
};
