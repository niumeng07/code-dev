#include <iostream>

using namespace std;

void test(int x) { cout << x << endl; }
int main(int argc, char *argv[]) {
    test(true ? 1 : 0);
    test(false ? 1 : 0);

    return 0;
}
