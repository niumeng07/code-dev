#include "header.h"

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> result;

        int num = 1;
        for (int i = 0; i < n; i++) {
            // 一共有N个数
            result.push_back(num);
            if (num * 10 <= n) {
                num *= 10;
            } else {
                 while (num % 10 == 9 || num + 1 > n) {
                    num /= 10;
                }
                num++;
            }
        }
        return result;
    }
};


int main(int argc, char *argv[]) {
    print_vector(Solution().lexicalOrder(100));
    print_vector(Solution().lexicalOrder(200));
    return 0;
}

// 1->10->100->11->12->13->...->20->21->...->99->
