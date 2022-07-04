#include <algorithm>
#include <vector>
using namespace std;

class CombinationSum {
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        std::vector<vector<int>> result;
        std::vector<int> comb;

        backTrack(result, comb, candidates, target);
        return result;
    }

    void backTrack(vector<vector<int>> &res, vector<int> comb,
                   vector<int> &cand, int target) {
        if (target == 0) {
            res.push_back(std::move(comb));
            return;
        }
        for (auto x : cand) {
            int back = comb.empty() ? 0 : comb.back();
            if (target >= x && back <= x) {
                comb.push_back(x);
                backTrack(res, comb, cand, target - x);
                comb.pop_back();
            }
        }
    }
};

void print_vector(const vector<int> &vec, const int& target) {
    for (const auto &item: vec) {
        cout << item << ",";
    }
    cout << "|" << target;
    cout << endl;
}
/* 怎么去重
 * 2, 2, 3,
 * 2, 3, 2,
 * 3, 2, 2,
 * 7,
 * */

class Solution {
public:
    void dfs(vector<int>& candidates, int target, vector<vector<int>>& result,
             vector<int>& sums) {
        // print_vector(sums, target);
        if (target == 0) {
            std::sort(sums.begin(), sums.end());
            if (find(result.begin(), result.end(), sums) == result.end()) {
                // cout << "push: ";
                // print_vector(sums, target);
                result.push_back(sums);
            }
            return;
        } else if (target < 0) {
            return;
        }
        for (int i = 0; i < candidates.size(); i++) {
            sums.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], result, sums);
            sums.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> sums;
        dfs(candidates, target, result, sums);
        // for (const auto& vec: result) {
        //     for (const auto& item: vec) {
        //         cout << item << ", ";
        //     }
        //     cout << endl;
        // }
        return result;
    }
};
