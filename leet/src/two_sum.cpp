/**
 * @brief
 *
 * Given an array of integers, return indices of the two numbers such
 * that they add up to a specific target.
 *
 * You may assume that each input would have exactly one solution, and you may
 * not use the same element twice.
 *
 * Example:
 * Given nums = [2, 7, 11, 15], target = 9,
 *
 * Because nums[0] + nums[1] = 2 + 7 = 9,
 * return [0, 1].
 */
#include <unordered_map>
#include <vector>
using namespace std;
class TwoSum {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> target_num;
        vector<int> result;
        target_num.resize(numbers.size());
        for (size_t i = 0; i < numbers.size(); i++) {
            target_num[i] = target - numbers[i];
        }
        for (size_t i = 0; i < target_num.size(); i++) {
            if (std::find(numbers, target_num[i]) != target_num.end()) {

            }
        }
        return result;
    }
};

int main(int argc, char *argv[]) {
    return 0;
}
