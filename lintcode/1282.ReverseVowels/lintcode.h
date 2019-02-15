class Solution {
public:
    /**
     * @param s: a string
     * @return: reverse only the vowels of a string
     */
    
    set<char> vowels;

    Solution() {
        vowels.insert('a');
        vowels.insert('e');
        vowels.insert('i');
        vowels.insert('o');
        vowels.insert('u');
        vowels.insert('A');
        vowels.insert('E');
        vowels.insert('I');
        vowels.insert('O');
        vowels.insert('U');
    }
    string reverseVowels(string &s) {
        // write your code here
        int i = 0;
        int j = s.size() - 1;
        while(i<j) {
            if(vowels.find(s[i]) == vowels.end()) {
                i++;
                continue;
            }
            if(vowels.find(s[j]) == vowels.end()) {
                j--;
                continue;
            }
            // swap
            char tmp = s[i];
            s[i] = s[j];
            s[j] = tmp;
            i++;
            j--;
        }
        return s;
    }
};
