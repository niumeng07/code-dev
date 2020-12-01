#include <iomanip>  // std::setprecision
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
    vector<float> x;
    x.push_back(0.00000123456789);
    x.push_back(0.123456789);
    x.push_back(0.00123456789);
    x.push_back(0.00000000123456788);
    x.push_back(0.00000123456789);
    x.push_back(1.23456/10000000000000);

    for (auto f : x) {
        cout << setprecision(20) << f << ", ";
    }
    cout << endl;
    return 0;
}
