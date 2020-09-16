#include <climits>
#include <iostream>
#include <vector>
using namespace std;

class RandomPickwithBlacklist {
public:
    // 1 <= N <= 1000000000, 按位保存需要 15625000 个uint64, 大概需要14M
    // 0 <= B.length < min(100000, N)
    vector<uint64_t> bits;
    RandomPickwithBlacklist(int N, vector<int>& B) {
        uint64_t bits_length = N / 64 + 1;
        for (size_t i = 0; i < bits_length; i++) {
            bits.push_back(ULLONG_MAX);
        }
        for (auto b : B) {
        }
    }

    // 产生一个随机数X, 0<=X<=N, 且N不属于B
    int pick() { return 0; }
};
