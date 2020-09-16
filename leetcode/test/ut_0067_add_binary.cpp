#include <iostream>

#include "0067_add_binary/add_binary.h"
#include "gtest/gtest.h"

using namespace std;

int main(int argc, char **argv) {
    string a = "1234";
    AddBinary su;
    cout << su.addBinary("1", "111") << endl;
    return 0;
}
// 1,3
// 0 2
// -1 1
