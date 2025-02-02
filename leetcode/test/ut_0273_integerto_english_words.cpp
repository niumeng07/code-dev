#include <iostream>

#include "0273_integerto_english_words/integerto_english_words.h"
#include "gtest/gtest.h"
using namespace std;

void makeTest(int num) {
    cout << "|" << num << "|" << IntegertoEnglishWords().numberToWords(num)
         << "|" << endl;
}
int main(int argc, char **argv) {
    makeTest(0);
    makeTest(9);
    makeTest(10);
    makeTest(11);
    makeTest(18);
    makeTest(20);
    makeTest(25);
    makeTest(45);
    makeTest(100);
    makeTest(105);
    makeTest(112);
    makeTest(812);
    makeTest(1000);
    makeTest(100812);
    makeTest(1000000);
    makeTest(10000001);
    makeTest(1234567891);

    return 0;
}
