#include <iostream>
#include <vector>

#include "0283_move_zeros/move_zeros.h"
#include "gtest/gtest.h"
using namespace std;

int main(int argc, char **argv) {
    vector<int> input({1, 2, 0, 3, 4, 0, 0, 5, 6, 7, 0, 0, 0});
    vector<int> input2({});
    vector<int> input3({0});
    vector<int> input4({0, 4});
    vector<int> input5({4});
    // MoveZeros su;
    MoveZeros().moveZeroes(input);
    MoveZeros().moveZeroes(input2);
    MoveZeros().moveZeroes(input3);
    MoveZeros().moveZeroes(input4);
    MoveZeros().moveZeroes(input5);
    printVector(input);
    printVector(input2);
    printVector(input3);
    printVector(input4);
    printVector(input5);
}
