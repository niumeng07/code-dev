#include <iostream>
#include <sstream>
using namespace std;

class Solution {
public:
    string vector_to_str(vector<int>& height) {
        stringstream str;
        for (int i = 0; i < height.size(); i++) {
            str << height[i] << ",";
        }
        return str.str();
    }
    void remove_head0(vector<int>& height) {
        if (height.size() == 0) return;
        for (size_t i = 0; i < height.size(); ++i) {
            if (height[i] <= 0) {
                height.erase(height.begin() + i, height.begin() + i + 1);
                i--;
            } else {
                break;
            }
        }
    }

    void remove_tail0(vector<int>& height) {
        if (height.size() == 0) return;
        for (size_t i = height.size() - 1; i >= 0; i--) {
            if (height[i] <= 0) {
                height.erase(height.end() - 1, height.end());
            } else {
                break;
            }
        }
    }
    void set_neg_to0(vector<int>& height) {
        if (height.size() == 0) return;
        for (int i = 0; i < height.size(); i++) {
            height[i] = max(height[i], 0);
        }
    }

    // O(N*K*K+2N)^2
    void trap_iteration(vector<int>& height, int& sum) {
        set_neg_to0(height);   // O(N)
        remove_head0(height);  // O(K)
        remove_tail0(height);  // O(K)
        if (height.size() <= 1) {
            return;
        }
        for (int i = 0; i < height.size(); i++) {  // O(N)
            if (height[i] == 0) {
                sum++;
            }
        }
        for (int i = 0; i < height.size(); i++) {  // O(N)
            height[i]--;
        }
        trap_iteration(height, sum);  // O(N*K*K+2N)^2
    }

    // 计算第i个位置上方能乘多少水,第i个能乘多少水,由其左右两的最大高度的较小值决定
    // 内在超了
    int trap2(vector<int>& height) {
        if (height.size() <= 2) {
            return 0;
        }
        size_t len = height.size();
        vector<int> left_max(len, 0);
        vector<int> right_max(len, 0);
        int max_value = 0;
        for (int i = 0; i < height.size(); i++) {
            left_max[i] = max_value;
            max_value = max(max_value, height[i]);
        }
        max_value = 0;
        for (int i = height.size() - 1; i >= 0; i--) {
            right_max[i] = max_value;
            max_value = max(max_value, height[i]);
        }
        int sum = 0;
        for (int i = 0; i <= height.size(); i++) {
            sum += max((min(left_max[i], right_max[i]) - height[i]), 0);
        }
        return sum;
    }
    // trap2上优化内存
    int trap3(vector<int>& height) {
        if (height.size() <= 2) {
            return 0;
        }
        vector<int> max_hills(height.size(), 0);
        int max_value = height[0];
        for (int i = 1; i < height.size() - 1; i++) {
            max_hills[i] = max_value;
            max_value = max(max_value, height[i]);
        }
        int sum = 0;
        max_value = height[height.size() - 1];
        for (int i = height.size() - 2; i > 0; i--) {
            max_value = max(max_value, height[i]);
            sum += max((min(max_hills[i], max_value) - height[i]), 0);
        }
        return sum;
    }

    int trap(vector<int>& height) {
        int sum = 0;
        // trap_iteration(height, sum); // 耗时太长
        // sum = trap2(height); // 内存超
        sum = trap3(height);
        // cout << "----------" << sum << endl;
        return sum;
    }
};
