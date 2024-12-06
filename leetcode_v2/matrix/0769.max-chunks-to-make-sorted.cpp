#include "header.h"
/*
给定一个长度为 n 的整数数组 arr ，它表示在 [0, n - 1] 范围内的整数的排列。
我们将 arr 分割成若干 块 (即分区)，并对每个块单独排序。将它们连接起来后，使得连接的结果和按升序排序后的原数组相同。
返回数组能分成的最多块数量。

示例 1:
输入: arr = [4,3,2,1,0]
输出: 1
解释:
将数组分成2块或者更多块，都无法得到所需的结果。
例如，分成 [4, 3], [2, 1, 0] 的结果是 [3, 4, 0, 1, 2]，这不是有序的数组。

示例 2:
输入: arr = [1,0,2,3,4]
输出: 4
解释:
我们可以把它分成两块，例如 [1, 0], [2, 3, 4]。
然而，分成 [1, 0], [2], [3], [4] 可以得到最多的块数。
对每个块单独排序后，结果为 [0, 1], [2], [3], [4]
*/

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        // 前面的块  必须小于 后面的块 （中的数字）
        // 对每一个数，其后是否有比其小的数，倒序找第一个
        // -->如果找到了，当前数到这个数是一个block
        // -->如果找不到, 当前数单独成block
        int m = arr.size();
        if (m <= 1) return m;

        vector<int> position(m, -1);
        for (int i = 0; i < m; i++) {
            for (int j = m - 1; j > i; j--) {
                if (arr[j] < arr[i]) {
                    position[i] = j;
                    break;
                }
            }
        }

        for (int i = 0; i < m;) {
            if (position[i] > 0) {
                int j = i + 1;
                for (j = i + 1; j < position[i]; j++) {
                    position[j] = 1;
                }
                i = j + 1;
            } else {
                 i++;
            }
        }

        int result = 0;
        for (int i = 0; i < position.size(); i++) {
            if (position[i] < 0) {
                result++;
            }
        }
        return result;
    }
};

int main(int argc, char const* argv[]) {
    // 4 4 4 4 -1
    vector<int> arr = {4, 3, 2, 1, 0};
    cout << Solution().maxChunksToSorted(arr) << " ==? 1" << endl;

    // 1 -1 -1 -1 -1
    arr = {1, 0, 2, 3, 4};
    cout << Solution().maxChunksToSorted(arr) << " ==? 4" << endl;

    arr = {2, 0, 1};
    cout << Solution().maxChunksToSorted(arr) << " ==? 1" << endl;
    return 0;
}
