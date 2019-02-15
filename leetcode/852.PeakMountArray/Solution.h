#include <vector>
using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int max = A[0];
        for(int i = 1; i < A.size(); i++) {
            if (A[i] >= max){
                max = A[i];
            } else {
                return i - 1;
            }
        }
        return A.size() - 1;
    }
};
