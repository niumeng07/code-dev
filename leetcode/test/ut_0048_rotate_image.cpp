#include <time.h>

#include <iostream>
#include <vector>

#include "0048_rotate_image/rotate_image.h"
#include "gtest/gtest.h"
using namespace std;

int main(int argc, char **argv) {
    RotateImage su;
    vector<vector<int> > matrix;
    vector<int> tmp({1, 2, 3, 4});
    vector<int> tmp2({5, 6, 7, 8});
    vector<int> tmp3({9, 10, 11, 12});
    vector<int> tmp4({13, 14, 15, 16});
    matrix.push_back(tmp);
    matrix.push_back(tmp2);
    matrix.push_back(tmp3);
    matrix.push_back(tmp4);
    for (auto vec : matrix) {
        for (auto x : vec) {
            cout << x << " ";
        }
        cout << endl;
    }
    clock_t start, end;
    start = clock();
    su.rotate(matrix);
    end = clock();
    cout << "time used: " << end - start << endl;
    for (auto vec : matrix) {
        for (auto x : vec) {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}
