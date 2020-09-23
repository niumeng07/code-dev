#include <iostream>
using namespace std;

void test1() {
    long x = 966367641600;
    cout << (x & 0x00000000ffffffff) << std::endl;
    cout << ((x & 0xffffffff00000000) >> 32) << std::endl;
    int a = 9;
    int b = 3;

    a = (a << 1);
    b = (b << 1);
    cout << a << "\t" << b << endl;
    a = (a >> 2);  // 4
    b = (b >> 2);  // 1
    cout << a << "\t" << b << endl;
}
void test2() {
    string x = "abb";
    int i = 'a';
    int j = 'a';
    for (auto c : x) {
        i = i ^ c;
        j = j ^ c;
    }
    cout << i << endl;
    x = "aaa";
    i = 'a';
    j = 'a';
    for (auto c : x) {
        i = i ^ c;
        j = j ^ c;
    }
    cout << i << endl;

}
int main(int argc, char *argv[]) {
    // test1();
    test2();
    return 0;
}
