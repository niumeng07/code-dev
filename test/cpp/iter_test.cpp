#include <boost/algorithm/string.hpp>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using namespace boost;

int main(int argc, char *argv[]) {
    vector<string> input({"a:1", "b:2", "c:3", "d:4", "e:5"});
    for (vector<string>::iterator it = input.begin(); it != input.end(); ++it) {
        cout << *it << "\t";
    }
    cout << endl;
    vector<string> _tempSplit;
    for (vector<string>::iterator it = input.begin(); it != input.end(); ++it) {
        boost::split(_tempSplit, *it, boost::is_any_of(":"));
        *it = _tempSplit[1];
    }
    for (vector<string>::iterator it = input.begin(); it != input.end(); ++it) {
        cout << *it << "\t";
    }
    cout << endl;
    for (vector<string>::iterator it = input.begin(); it != input.end(); ++it) {
        cout << it - input.begin() << "\t";
    }
    cout << endl;
    return 0;
}
