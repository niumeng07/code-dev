#include <iomanip>  // std::setprecision
#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
    float x = 0.1000101;
    cout << std::setprecision(20) << x << endl;
    return 0;
}
