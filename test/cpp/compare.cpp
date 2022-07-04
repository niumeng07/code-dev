#include <iostream>
using namespace std;

void test() {
    std::cout << std::max((uint64_t)1, (uint64_t)2) << std::endl;
}
void test1() {
    float x = 0.0;
    if (x == 0.0) {
        cout << "equal" << endl;
    }
}

int main(int argc, char *argv[]) {
    test();
    return 0;
}
