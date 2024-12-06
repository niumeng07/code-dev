#include "header.h"

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        std::vector<int> h;
        std::make_heap(h.begin(), h.end());
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                h.push_back(matrix[i][j]);
                std::push_heap(h.begin(), h.end());
                if (h.size() > k) {  // 这里是>而不是>=，并在返回前再pop一次，防止K=0的情况
                    std::pop_heap(h.begin(), h.end());
                    h.pop_back();
                }
            }
        }
        std::pop_heap(h.begin(), h.end());
        return h.back();
    }
};

int main(int argc, char* argv[]) {
    vector<vector<int>> matrix = {{1, 5, 9}, {10, 11, 13}, {12, 13, 15}};
    cout << Solution().kthSmallest(matrix) << endl;
    return 0;
}
