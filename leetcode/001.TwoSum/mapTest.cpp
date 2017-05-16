#include <map>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

int main()
{
    map<int, string> m1;
    unordered_map<int, string> m2;
    unordered_map<string, int> m3;

    m1[1] = "m1-1";
    m1[2] = "m1-2";
    m1[3] = "m1-3";
    m2[1] = "m2-1";
    m2[4] = "m2-4";
    
    cout << m1[1] << endl;
    cout << m2[4] << endl;
    
    if( m2.find(1) != m2.end())
        cout << "m2.find(1)" << endl;
    else 
        cout << "m2 not find 1" << endl;
    int a = 100 ;
    string as = to_string(a );

    return 0;
}
