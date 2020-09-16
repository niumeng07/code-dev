#include <iostream>
#include <vector>

#include "0200_numberof_islands/numberof_islands.h"
#include "gtest/gtest.h"
using namespace std;

int main(int argc, char **argv) {
    NumberofIslands su;
    vector<vector<char> > X = {{'1', '1', '1', '1', '0'},
                               {'1', '1', '0', '1', '0'},
                               {'1', '1', '0', '0', '0'},
                               {'0', '0', '0', '0', '0'}};
    cout << su.numIslands(X) << endl;
    return 0;
}
