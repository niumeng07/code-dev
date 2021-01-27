#include <fstream>
#include <boost/algorithm/string.hpp>
#include <iostream>
#include <vector>

using namespace std;
using namespace boost;

void test1() {
        ifstream is("test.txt");
    char buffer[256];
    while(is){
        is.getline(buffer, 1000);
        cout << buffer << endl;
    }


    cout << "-------------------------------------" << endl;
    string s = "a,b, c ,,e,f,";
    vector <string> fields;
    split( fields, s, is_any_of( "," ) );
    for (auto item: fields) {
        cout << item << "\t";
    }
    cout << endl;
    split( fields, s, is_any_of( " ," ) );
    for (auto item: fields) {
        cout << item << "\t";
    }
    cout << endl;
    split( fields, s, is_any_of( " ," ), token_compress_on );
    for (auto item: fields) {
        cout << item << "\t";
    }
    cout << endl;

}

void test2() {
    string x = "aa\001bb";
    vector<string> y;
    boost::split(y, x, "\001");
}

int main() {
    // test1();
    test2();
    return 0;
}

