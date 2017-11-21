#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int lengthOfLongestSubstring_Re(string inpt) {
    int maxlen = 1;
    unordered_map<int,int> position;
    int i = 0;
    for(int j = 0; j < inpt.length(); j++ ) {
        if (position.find(inpt[j]) != position.end() ){
            maxlen = (j - i + 1 ) > maxlen ? (j - i + 1) : maxlen;
            i = j + 1;
        }
        else{
            position[inpt[j] ] = j;
        }
    }
    return maxlen;
}
