#include <iostream>
#include <vector>

#include "0037_sudoku_solver/sudoku_solver.h"
#include "gtest/gtest.h"

using namespace std;

int main(int argc, char **argv) {
    vector<vector<char> > board;
    vector<char> row({'5', '3', '.', '.', '7', '.', '.', '.', '.'});
    board.push_back(row);
    row = {'6', '.', '.', '1', '9', '5', '.', '.', '.'};
    board.push_back(row);
    row = {'.', '9', '8', '.', '.', '.', '.', '6', '.'};
    board.push_back(row);
    row = {'8', '.', '.', '.', '6', '.', '.', '.', '3'};
    board.push_back(row);
    row = {'4', '.', '.', '8', '.', '3', '.', '.', '1'};
    board.push_back(row);
    row = {'7', '.', '.', '.', '2', '.', '.', '.', '6'};
    board.push_back(row);
    row = {'.', '6', '.', '.', '.', '.', '2', '8', '.'};
    board.push_back(row);
    row = {'.', '.', '.', '4', '1', '9', '.', '.', '5'};
    board.push_back(row);
    row = {'.', '.', '.', '.', '8', '.', '.', '7', '9'};
    board.push_back(row);
    SudokuSolver su;
    return 0;
}
