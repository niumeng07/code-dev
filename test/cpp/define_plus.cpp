#include <iostream>
#include <string>
#include <algorithm>  
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/split.hpp>
#include <boost/lexical_cast.hpp>

using namespace boost;
using namespace std;


int string2int(string& start) {
    int sum1 = 0;
    if (!start.empty()) {
        int num = 0;
        for (int i = 0; i < start.size(); i++) {
            if (start[i] >= 'A' && start[i] <= 'Z') {
                num = start[i] - 'A' + 10;
                sum1 = sum1 * 36 + num;
            } else if (start[i] >= '0' && start[i] <= '9') {
                num = start[i] - '0';
                sum1 = sum1 * 36 + num;
            }
        }
    }
    return sum1;
}

string int2string(int& total) {
    string str3;
    int t = 0;
    while (1) {
        t = total % 36;
        total /= 36;
        if (t >= 10 && t < 36)
            str3 = (char)(t - 10 + 'A') + str3;
        else
            str3 = char(t + '0') + str3;
        if (total == 0) break;
    }
    str3 = string(7 - str3.size(), '0') + str3;
    return str3;
}
string step(string start) {
    int sum1 = string2int(start);   
    
    int total = sum1 + 1;
    string str3 = int2string(total);
    
    return str3;
}

int main(int argc, char *argv[]) {
    string x1 = "0000000";
    for (size_t i = 0; i < 10000000; i++) {
        reverse(x1.begin(), x1.end());
        x1 = step(x1);
        cout << x1 << endl;
        reverse(x1.begin(), x1.end());
    }
    return 0;
}
