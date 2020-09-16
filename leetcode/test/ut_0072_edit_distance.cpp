#include <iostream>

#include "0072_edit_distance/edit_distance.h"
#include "gtest/gtest.h"
using namespace std;
int main(int argc, char **argv) {
    EditDistance su;
    cout << su.minDistance("abc", "abd") << endl;
    return 0;
}
