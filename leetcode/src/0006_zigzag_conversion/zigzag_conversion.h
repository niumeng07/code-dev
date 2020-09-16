#include <iostream>
#include <string>
#include <vector>
/**
 * @brief
 * 该题描述十分不清楚，对于偶数行的理解十分不确定，跳过
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number
 * of rows like this: (you may want to display this pattern in a fixed font for
 * better legibility)
 *
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 * And then read line by line: "PAHNAPLSIIGYIR"
 * Write the code that will take a string and make this conversion given a
 * number of rows:
 *
 * string convert(string text, int nRows);
 * convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
 * PAYPALISHIRING
 * PAY P ALI S HIR I NG
 * ABC 2
 * A
 * B C
 * ABCD 2
 * A C
 * B   D
 *
 */
using namespace std;
class ZigzagConversion {
public:
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
                    if (i < tmp[t].size()) result += tmp[t][i];
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
