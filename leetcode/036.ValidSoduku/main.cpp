#include "Solution.h"
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    Solution su;
    vector<vector<char> > matrix;
    vector<char> tmp({'.','.','.','.','.','.','.','.','.'});
    for(int i = 0; i < 9; i++ )
    {
        matrix.push_back(tmp);
    }
    matrix[0][0] = '1';
    su.isValidSudoku(matrix);
    return 0;
}
