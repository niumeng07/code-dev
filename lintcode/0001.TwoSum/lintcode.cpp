#include <algorithm>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
  /**
   * @param numbers: An array of Integer
   * @param target: target = numbers[index1] + numbers[index2]
   * @return: [index1, index2] (index1 < index2)
   */
  vector<int> twoSum(vector<int> &numbers, int target) {
    // write your code here
    vector<int> result;
    std::map<int, int> position; //{need_num: cur_index}
    for (int i = 0; i < numbers.size(); i++) {
      position[target - numbers[i]] = i;
    }
    for (int i = 0; i < numbers.size(); i++) {
      if (position.find(numbers[i]) != position.end()) {
        if (i < position[numbers[i]]) {
          result.push_back(i);
          result.push_back(position[numbers[i]]);
        } else {
          result.push_back(position[numbers[i]]);
          result.push_back(i);
        }
        break;
      }
    }
    return result;
  }
};
