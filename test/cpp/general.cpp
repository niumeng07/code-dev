#include <iostream>
using namespace std;

void test1() {
    int curr_num = 11;
    curr_num = curr_num > 10 ? 10 : curr_num;
    cout << curr_num << endl;
}

int main(int argc, char *argv[]) {
    test1();
    return 0;
}
