#include "header.h"
/*
 * 存在一个 无向图 ，图中有 n 个节点。其中每个节点都有一个介于 0 到 n - 1 之间的唯一编号。
 * 给你一个二维数组 graph ，其中graph[u] 是一个节点数组，由节点 u 的邻接节点组成。
 * 形式上，对于 graph[u] 中的每个 v ，都存在一条位于节点 u 和节点 v 之间的无向边。
 * 该无向图同时具有以下属性：
 * - 不存在自环（graph[u] 不包含 u）。
 * - 不存在平行边（graph[u] 不包含重复值）。
 * - 如果v 在 graph[u] 内，那么 u 也应该在 graph[v] 内（该图是无向图）
 * - 这个图可能不是连通图，也就是说两个节点 u 和 v 之间可能不存在一条连通彼此的路径。
 *
 * 二分图 定义：如果能将一个图的节点集合分割成两个独立的子集 A 和 B，
 * 并使图中的每一条边的两个节点一个来自 A 集合，一个来自 B 集合，就将这个图称为 二分图 。
 *
 * 如果图是二分图，返回 true ；否则，返回 false 。
 *
 * 示例 1：
 * 输入：graph = [[1,2,3],[0,2],[0,1,3],[0,2]]
 * 输出：false
 * 解释：不能将节点分割成两个独立的子集，以使每条边都连通一个子集中的一个节点与另一个子集中的一个节点。
 *
 * 示例 2：
 * 输入：graph = [[1,3],[0,2],[1,3],[0,2]]
 * 输出：true
 * 解释：可以将节点分成两组: {0, 2} 和 {1, 3} 。
 * */

class Solution {
public:
    bool result = true;
    int g_size = 0;

    void DFS(int node, int curr_color, vector<vector<int>>& graph, vector<int>& color) {
        color[node] = curr_color;
        int neighbor_color = 3 - curr_color;  // neighbor需要的颜色

        for (const auto& neighbor : graph[node]) {  // 当前点和每个neighbor判断
            // cout << node << ": " << color[node] << ", " << neighbor << ": " << color[neighbor] << endl;
            if (color[neighbor] == 0) {  // 如果neighbor未染色,把neighbor染色为和当前node不同的颜色
                DFS(neighbor, neighbor_color, graph, color);
                if (result == false) {  // 当前这条路已经走不通了
                    return;
                }
            } else {                                      // neighbor已经染色
                if (color[neighbor] != neighbor_color) {  // 当前这一条路已经走不通了
                    result = false;                       // 有没有可能还有其它分法？-->不可能，该题只能贪婪的解
                    return;
                }
            }
        }
    }

    bool isBipartite(vector<vector<int>>& graph) {
        this->g_size = graph.size();  // 一共有多少个点

        if (this->g_size <= 2) {
            return true;
        }
        vector<int> color(this->g_size, 0);

        // DFS(0, 1, graph, color);
        for (int i = 0; i < this->g_size; i++) {
            if (color[i] == 0) {
                // 这里为什么是必须的?
                // 这里主要是为了防止有孤点（如果能保证所有的点都是联通的，实际上不需要这个循环
                // 那么，如果一个点已经被赋值了，是不能强制修改为了1的
                DFS(i, 1, graph, color);
            }
        }

        return this->result;
    }
};

int main(int argc, char* argv[]) {
    vector<vector<int>> graph = {{1, 2, 3}, {0, 2}, {0, 1, 3}, {0, 2}};
    cout << Solution().isBipartite(graph) << endl;

    graph = {{1, 3}, {0, 2}, {1, 3}, {0, 2}};
    cout << Solution().isBipartite(graph) << endl;
    return 0;
}
