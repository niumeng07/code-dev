#include "Solution.h"
#include <vector>
#include <iostream>
#include <time.h>
using namespace std;

int main(){
    Solution su;
    vector<vector<int> > matrix;
    vector<int> tmp({1,2});
    matrix.push_back(tmp);
    vector<int> tmp2({3,4});
    matrix.push_back(tmp2);
    for(auto vec : matrix){
        for(auto x : vec){
            cout << x << " ";
        }
        cout << endl;
    }
    clock_t start, end;
    start = clock();
    su.rotate(matrix);
    end = clock();
    cout << "time used: " << end - start << endl;
    for(auto vec : matrix){
        for(auto x : vec){
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}
