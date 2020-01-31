#include "gtest/gtest.h"
#include <iostream>
#include <vector>
#include "0051_n_queens/n_queens.h"
#include <time.h>
using namespace std;
int main()
{
    Solution su;
	clock_t start, end;
	start = clock();
    vector<vector<string> > res = su.solveNQueens(6);
	end = clock();
    for(auto vec : res)
    {
        for (auto x : vec)
            cout << x << ", ";
        cout << endl;
    }
	cout << "Time used: " << end - start << endl;
    return 0;
}
