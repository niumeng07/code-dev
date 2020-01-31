#include "gtest/gtest.h"
#include "0050_pow_x_n/pow_x_n.h"
#include <iostream>
#include <time.h>
#include <stdint.h>
using namespace std;
int main()
{
    Solution su;
    clock_t start, end;
    uint64_t time = 0;
    for(int i = 0; i< 10000; i++)
    {
        start = clock();
        su.myPow(10,20);
        time += clock() - start;
    }
    cout << time << endl;
    return 0;
}
