#include "gtest/gtest.h"
#include "0009_palindrome_number/palindrome_number.h"

int main()
{
    Solution su;
    cout << su.isPalindrome(12345) << endl;
    cout << su.isPalindrome(12345783) << endl;
    cout << su.isPalindrome(1) << endl;
    return 0;
}
