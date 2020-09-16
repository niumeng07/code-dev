#include <iostream>
#include <vector>

#include "0036_valid_soduku/valid_soduku.h"
#include "gtest/gtest.h"
using namespace std;
int main(int argc, char **argv) {
    ValidSoduku su;
    vector<vector<char> > matrix;
    vector<char> tmp({'.', '.', '.', '.', '.', '.', '.', '.', '.'});
    for (int i = 0; i < 9; i++) {
        matrix.push_back(tmp);
    }
    matrix[0][0] = '1';
    su.isValidSudoku(matrix);
    return 0;
}
