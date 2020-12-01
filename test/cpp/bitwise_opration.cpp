#include <iostream>
#include <vector>
#include <sstream>
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
void test3() {
    vector<int> x({10, 1, 1, 1, 1});
    int bizSum = 0;
    for (auto i : x) {
        bizSum = (bizSum << 1) + i;
    }
    cout << bizSum << endl;
    for (int i = 0; i < x.size()-1; i++) {
        cout << (bizSum & 1) << endl;
        bizSum = bizSum >> 1;
    }
    cout << bizSum << endl;
}

string printList(vector<int> &x) {
    stringstream ss;
    for (auto i : x) {
        ss << i << ",";
    }
    return ss.str();
}
int hashv(vector<int> x) {
    int bizSum = 0;
    for (auto i : x) {
        bizSum = (bizSum << 1) + i;
    }
    cout << printList(x) << bizSum << endl;
    return bizSum;
}
void test4() {
    int max = 0;
    for (int a=0; a<=10; a++) {
        for (int b= 0; b<=1; b++) {
            for (int c= 0; c<=1; c++) {
                for (int d= 0; d<=1; d++) {
                    for (int e= 0; e<=1; e++) {
                        int bizSum = hashv({a, b, c, d, e});
                        if (bizSum > max)
                            max = bizSum;
                    }
                }
            }
        }
    }
    cout << max << endl;
}

uint32_t get_bitmove(int x, int y) { return (x << 5) + y; }
void test5() {
    int x = get_bitmove(2, 1);
    cout << x << ", " << ((x & 0b111111110000) >> 5) << ", " << (x & 0b00001111) << endl;
    x = get_bitmove(14, 4);
    cout << x << ", " << ((x & 0b111111110000) >> 5) << ", " << (x & 0b00001111) << endl;
    x = get_bitmove(10, 2);
    cout << x << ", " << ((x & 0b111111110000) >> 5) << ", " << (x & 0b00001111) << endl;
    x = get_bitmove(1, 1);
    cout << x << ", " << ((x & 0b111111110000) >> 5) << ", " << (x & 0b00001111) << endl;
}

void test6() {
    int x = get_bitmove(13, 10);
    cout << x << endl;
}

int main(int argc, char *argv[]) {
    // test1();
    // test2();
    // test3();
    // test4();
    // test5();
    test6();
    return 0;
}
