#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  string add(string num1, string num2) {
    string result = "";
    int i = num1.size() - 1;
    int j = num2.size() - 1;
    int step = 0;
    int x = 0;
    while (i >= 0 && j >= 0) {
      x = ((num1[i] - '0') + (num2[j] - '0'));
      string tmp(1, (x % 10 + step + '0'));
      result.insert(0, tmp);
      step = x / 10;
      i--;
      j--;
    }
    while (i >= 0) {
      x = (num1[i] - '0');
      string tmp(1, (x % 10 + step + '0'));
      result.insert(0, tmp);
      step = x / 10;
      i--;
    }
    while (j >= 0) {
      x = (num2[j] - '0');
      string tmp(1, (x % 10 + step + '0'));
      result.insert(0, tmp);
      step = x / 10;
      j--;
    }
    if (step > 0) {
      string tmp(1, step + '0');
      result.insert(0, tmp);
    }
    return result;
  }
  string oxo(char num1, char num2, int zs) {
    string result = "";
    int x= (num1 - '0') * (num2 - '0');
    string tmp(1, x % 10 + '0');
    result.insert(0, tmp);
    if (x >= 10) {
      string tmp(1, x / 10 + '0');
      result.insert(0, tmp);
    }
    for (int i = 0; i < zs; i++) {
      result.append("0");
    }
    return result;
  }
  string multiply(string num1, string num2) {
    if (num1 == "0" || num2 == "0")
      return "0";
    string result = "";
    for (int i = num1.size() - 1; i >= 0; i--) {
      for (int j = num2.size() - 1; j >= 0; j--) {
        result = this->add(
            result, this->oxo(num1[i], num2[j],
                              num1.size() - 1 - i + num2.size() - 1 - j));
      }
    }
    return result;
  }
};
