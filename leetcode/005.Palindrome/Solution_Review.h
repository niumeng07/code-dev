#include <string>
#include <iostream>
using namespace std;

class Solution_Review{
    // 从中间往两边延伸，并记下当前最长串的左右顶点
    string findLongPalind(string input)
    {
        int left = 0, right = 0;
        int maxlen = 0;
        for(int i = 0; i < input.size(); i++){
            for(int j = 0; ;){
                if( i - j < 0 || i + j > input.size())
                    break;
                if(input[i-j] != input[i+j] )
                    break;
                if( 2*j + 1 > maxlen){
                    left = i - j;
                    right = i + j;
                    maxlen = 2 * j + 1;
                }
                j++;
            }
        }
        return input.substr(left, right);
    }
};
