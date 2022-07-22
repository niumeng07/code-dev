#include <math.h>
#include <stdio.h>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    double a = 0.0;
    cout << isnan(-1.0/a) << endl;
    cout << isnan(1.0/a) << endl;
    return 0;
}
