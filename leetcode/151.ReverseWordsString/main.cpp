#include <string>
#include <iostream>
#include "Solution.h"
using namespace std;

int main() {
    Solution su;
    string input = "the sky is blue";
    su.reverseWords(input);
    cout << input << endl;
}
