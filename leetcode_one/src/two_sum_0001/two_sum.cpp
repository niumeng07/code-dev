#include "two_sum_0001/two_sum.h"
#include <unordered_map>
#include <vector>

vector<int> TwoSum::twoSum(vector<int> &numbers, int target) {
  unordered_map<int, int> hash;
  vector<int> result;
  for (int i = 0; i < numbers.size(); i++) {
    int numberToFind = target - numbers[i];

    if (hash.find(numberToFind) != hash.end()) {
      result.push_back(hash[numberToFind]);
      result.push_back(i);
      return result;
    }
    hash[numbers[i]] = i;
  }
  return result;
}
