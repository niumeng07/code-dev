#include <math.h>
#include <iostream>
#include <fstream>
#include <random>
#include <time.h>

float random_float(float min, float max) {
	return ((float)rand() / RAND_MAX) * (max - min) + min;
}

using namespace std;
int main(int argc, char *argv[])
{
    float a;
    float b;
    clock_t t1, t2;
    clock_t elp1 = 0;
    clock_t elp2 = 0;

    ofstream outf;
    outf.open("./out.txt");
    srand(time(NULL));
    for(int i = 0; i < 10000; i++) {
        a = random_float(0, 100);
        //if(i<10) cout << a << endl;
        t1 = clock();
        b = a * a;
        t2 = clock();
        outf << a << b << endl;
        elp1 += (t2 - t1);
    }
    for(int i = 0; i < 10000; i++) {
        a = random_float(0, 100);
        //if(i<10) cout << a << endl;
        t1 = clock();
        b = pow(a, 2.0);
        t2 = clock();
        outf << a << b << endl;
        elp2 += (t2 - t1);
    }
    cout << elp1 << endl;
    cout << elp2 << endl;
    outf.close();
    return 0;
}
