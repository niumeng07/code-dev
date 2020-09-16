#include <iostream>
#include <vector>
using namespace std;

class MoveZeros {
public:
    void moveZeroes(vector<int> &nums) {
        int i = 0, j = 0;
        int size = nums.size();
        while (i < size && j < size) {
            if (nums[i] == 0) {
                j = i + 1;
                while (nums[j] == 0 && j < size) j++;
                if (j >= size) break;
                nums[i] = nums[j];
                nums[j] = 0;
            }
            i++;
        }
        for (int k = i + 1; k < size; k++) nums[k] = 0;
    }
};
void printVector(vector<int> &a) {
    for (auto x : a) cout << x << "\t";
    cout << endl;
}
