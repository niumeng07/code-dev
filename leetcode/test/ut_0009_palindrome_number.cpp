#include "0009_palindrome_number/palindrome_number.h"
#include "gtest/gtest.h"

// Expect false
TEST(palindrome_number, test0) {
  EXPECT_EQ(PalindromeNumber().isPalindrome(1234), false);
  EXPECT_EQ(PalindromeNumber().isPalindrome(12345783), false);
  EXPECT_FALSE(PalindromeNumber().isPalindrome(123));
  EXPECT_EQ(PalindromeNumber().isPalindromeUint64(1234), false);
  EXPECT_EQ(PalindromeNumber().isPalindromeUint64(12345783), false);
  EXPECT_FALSE(PalindromeNumber().isPalindromeUint64(123));
}

// Expect true
TEST(palindrome_number, test1) {
  EXPECT_EQ(PalindromeNumber().isPalindrome(1), true);
  EXPECT_TRUE(PalindromeNumber().isPalindrome(12321));
  EXPECT_TRUE(PalindromeNumber().isPalindrome(0));
  EXPECT_EQ(PalindromeNumber().isPalindromeUint64(1), true);
  EXPECT_TRUE(PalindromeNumber(true).isPalindromeUint64(12321));
  EXPECT_TRUE(PalindromeNumber().isPalindromeUint64(0));
  EXPECT_TRUE(PalindromeNumber().isPalindromeUint64((uint64_t)11111432500523411111));
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
