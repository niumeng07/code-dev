#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0;
        unordered_map<char, int> secret_diff;
        unordered_map<char, int> guess_diff;
        for (int i = 0; i < secret.size() && i < guess.size(); i++) {
            if (secret[i] == guess[i]) {
                bulls++;
            } else {
                secret_diff[secret[i]]++;
                guess_diff[guess[i]]++;
            }
        }
        int cows = 0;
        for (const auto& item : secret_diff) {
            
        }
        return "";
    }
};
