#include <stdint.h>
#include <time.h>

#include <iostream>

#include "0050_pow_x_n/pow_x_n.h"
#include "gtest/gtest.h"

TEST(pow_x_n, test0) {
    clock_t start, end;
    uint64_t time = 0;
    for (int i = 0; i < 10000; i++) {
        start = clock();
        PowXN().Pow(4.25, 20);
        time += clock() - start;
    }
    std::cout << time << ", " << PowXN().Pow(4.25, 20) << std::endl;
}

TEST(pow_x_n, test1) {
    clock_t start, end;
    uint64_t time = 0;
    for (int i = 0; i < 10000; i++) {
        start = clock();
        PowXN().myPow(4.25, 20);
        time += clock() - start;
    }
    std::cout << time << ", " << PowXN().myPow(4.25, 20) << std::endl;
}

TEST(pow_x_n, test2) {
    clock_t start, end;
    uint64_t time = 0;
    for (int i = 0; i < 10000; i++) {
        start = clock();
        PowXN().forPow(4.25, 20);
        time += clock() - start;
    }
    std::cout << time << ", " << PowXN().forPow(4.25, 20) << std::endl;
}
using namespace std;
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
