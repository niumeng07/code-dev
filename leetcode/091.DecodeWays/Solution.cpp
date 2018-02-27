#include <string> 
#include <vector>
#include <iostream>
using namespace std;

void dfs(string &tmp, vector<string>& result, string input, int index){
}
class Solution {
public:
    int numDecodings(string s) {
        vector<string> result;
        string tmp;
        dfs(tmp, result, s, 0);
        return result.size();
    }
};

int main(){
    string input = "12";
}
