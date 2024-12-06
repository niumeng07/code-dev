#include "header.h"

class Solution {
public:
    int side_length = 0;
    int sticks_num = 0;

    bool dfs(vector<int>& matchsticks, vector<int>& edges, int index) {
        if (sticks_num == index) {  // sticks用完了
            return true;
        }

        // 还有 index 没用完，尝试把当前sticks放入每一个edges
        for (size_t i = 0; i < 4; i++) {  // edges.size() 为4,直接写死
            if (edges[i] + matchsticks[index] > side_length) {
                // 放不进去,直接尝试往下一条边放，如果都放不进去，则退出for循环直接返回false
                continue;
            } else {  // 放的进去,DFS,并且也要尝试往下一条边里放
                edges[i] += matchsticks[index];
                if (dfs(matchsticks, edges, index+1)) {
                    return true;
                }
                edges[i] -= matchsticks[index];
            }
        }

        return false;
    }

    bool makesquare(vector<int>& matchsticks) {
        int sum = std::accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (sum % 4 != 0) {
            return false;
        }
        std::sort(matchsticks.begin(), matchsticks.end(), std::greater<int>());
        side_length = sum / 4;    // 边长
        int index = 0;            // 已经使用的sticks计数
        sticks_num = matchsticks.size();
        vector<int> edges(4, 0);  // 每条边已经有的长度

        return dfs(matchsticks, edges, 0);
    }
};
// 首先求得每条边的长度 sum(matchsticks)/4
// 如果不是整数  => false
// 如果是整数
// ==> 把 matchsticks 分为4组   搜索？

int main(int argc, char* argv[]) {
    vector<int> matchsticks = {1, 1, 2, 2, 2};
    cout << Solution().makesquare(matchsticks) << ", ==1?" << endl;
    ;

    matchsticks = {3, 3, 3, 3, 4};
    cout << Solution().makesquare(matchsticks) << ", ==0?" << endl;

    matchsticks = {8, 16, 24, 32, 40, 48, 56, 64, 72, 80, 88, 96, 104, 112, 60};
    cout << Solution().makesquare(matchsticks) << ", ==0?" << endl;
    return 0;
}
