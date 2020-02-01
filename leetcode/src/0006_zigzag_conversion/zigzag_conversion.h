#include <iostream>
#include <string>
#include <vector>
using namespace std;
class ZigzagConversion {
public:
  /*
   * 思路: 见readme
   * */
  string convert(string s, int numRows) {
    vector<string> tmp;
    bool N = true;
    int start = 0;
    while (start < s.length()) {
      if (N == true) {
        tmp.push_back(s.substr(start, numRows));
        start = start + numRows;
        N = false;
      } else if (N == false) {
        tmp.push_back(s.substr(start, 1));
        start = start + 1;
        N = true;
      }
    }
    string result = "";
    int i = 0;
    int mid = (numRows + 1) / 2 - 1;
    for (int k = 0; k < numRows; k++) {
      if (k != mid) {
        for (int t = 0; t < tmp.size(); t += 2) {
          if (i < tmp[t].size())
            result += tmp[t][i];
        }
        i++;
      }
      if (k == mid) {
        for (int t = 0; t < tmp.size(); t++) {
          if (t % 2 == 0 && i < tmp[t].size())
            result += tmp[t][i];
          else if (t % 2 == 1)
            result += tmp[t][0];
        }
        i++;
      }
    }
    cout << "result: " << result << endl;
    return result;
  }
};
