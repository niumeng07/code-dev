#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  void moveZeroes(vector<int> &nums) {
    int i = 0, j = 0;
    int size = nums.size();
    while (i < size && j < size) {
      if (nums[i] == 0) {
        j = i + 1;
        while (nums[j] == 0 && j < size)
          j++;
        if (j >= size)
          break;
        nums[i] = nums[j];
        nums[j] = 0;
      }
      i++;
    }
    for (int k = i + 1; k < size; k++)
      nums[k] = 0;
  }
};

void trimLeftTrailingSpaces(string &input) {
  input.erase(input.begin(), find_if(input.begin(), input.end(),
                                     [](int ch) { return !isspace(ch); }));
}

void trimRightTrailingSpaces(string &input) {
  input.erase(
      find_if(input.rbegin(), input.rend(), [](int ch) { return !isspace(ch); })
          .base(),
      input.end());
}

vector<int> stringToIntegerVector(string input) {
  vector<int> output;
  trimLeftTrailingSpaces(input);
  trimRightTrailingSpaces(input);
  input = input.substr(1, input.length() - 2);
  stringstream ss;
  ss.str(input);
  string item;
  char delim = ',';
  while (getline(ss, item, delim)) {
    output.push_back(stoi(item));
  }
  return output;
}

string integerVectorToString(vector<int> list, int length = -1) {
  if (length == -1) {
    length = list.size();
  }

  if (length == 0) {
    return "[]";
  }

  string result;
  for (int index = 0; index < length; index++) {
    int number = list[index];
    result += to_string(number) + ", ";
  }
  return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
  string line;
  while (getline(cin, line)) {
    vector<int> nums = stringToIntegerVector(line);

    Solution().moveZeroes(nums);

    string out = integerVectorToString(nums);
    cout << out << endl;
  }
  return 0;
}
