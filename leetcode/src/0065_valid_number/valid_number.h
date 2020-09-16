#include <iostream>

using namespace std;
class ValidNumber {
public:
    bool isNumber2(string s, bool isRight) {
        if (s.length() == 0) return false;
        int dotNumber = 0;
        if (char(s[0]) == '-' || char(s[0]) == '+' || char(s[0]) == '.') {
            if (s.length() == 1) return false;
            dotNumber = ((char(s[0]) == '.') ? 1 : 0);
            s = s.substr(1, s.length() - 1);
        }
        int numNumber = 0;
        for (int i = 0; i < s.length(); i++) {
            if (char(s[i]) <= '9' && char(s[i]) >= '0') numNumber++;
            if (char(s[i]) == '.' && dotNumber > 0) return false;
            if (char(s[i]) == '.')
                dotNumber++;
            else if (char(s[i]) < '0' || char(s[i]) > '9')
                return false;
        }
        if (numNumber == 0) return false;
        if (isRight == true && dotNumber > 0) return false;
        return true;
    }

    bool isNumber(string s) {
        s.erase(0, s.find_first_not_of(" "));
        s.erase(s.find_last_not_of(" ") + 1);
        int eNumber = 0;
        int ePos = 0;
        for (int i = 0; i < s.length(); i++) {
            if (char(s[i]) == 'e') {
                eNumber++;
                ePos = i;
            }
        }
        if (eNumber > 1) return false;
        if (eNumber == 0)
            return isNumber2(s, false);
        else {
            string left = s.substr(0, ePos);
            string right = s.substr(ePos + 1, s.length() - ePos - 1);
            return isNumber2(left, false) && isNumber2(right, true);
        }
    }
};
