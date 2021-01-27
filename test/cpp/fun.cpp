#include <iostream>
#include <map>
using namespace std;

void test(int b, int a = 1, const map<int, int> &x = map<int, int>()) {
    cout << a << endl;
    // x[1] = 1;
}

int main(int argc, char *argv[]) {
    test(1);
    return 0;
}
