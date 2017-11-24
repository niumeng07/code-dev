#include <iostream>
#include <string>
#include <limits>
using namespace std;

int str2int(string input){
    long result = 0;
    int flag = 1;
    if(input.substr(0, 1) == "-") {
        flag = -1;
        input = input.substr(1, input.size() - 1);
    }
    if(input.substr(0, 1) == "+") {
        flag = 1;
        input = input.substr(1, input.size() - 1);
    }
    for(int i = 0; i < input.size(); i++){
        if(input[i] <'0' || input[i] > '9' )
            return 0;
        result = result * 10 + (input[i] - '0');
        if(result > numeric_limits<int>::max() || result < numeric_limits<int>::min() )
            return 0;
    }
    return result*flag;
}
int main(){
    string x = "123456";
    cout << str2int(x) << endl;
    cout << str2int("-1293843939") << endl;
    cout << str2int("+1293843939") << endl;
    cout << str2int("001293843939") << endl;
    cout << str2int("a001293843939") << endl;
    return 0;
}
