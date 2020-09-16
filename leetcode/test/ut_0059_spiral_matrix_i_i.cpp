#include <iostream>

#include "0059_spiral_matrix_i_i/spiral_matrix_i_i.h"
#include "gtest/gtest.h"

using namespace std;

int main(int argc, char **argv) {
    SpiralMatrixII su;
    vector<vector<int>> result = su.generateMatrix(4);
    for (auto vec : result) {
        for (auto x : vec) cout << x << "\t" << ends;
        cout << endl;
    }
    return 0;
}
