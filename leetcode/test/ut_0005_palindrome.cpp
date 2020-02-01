#include "0005_palindrome/palindrome.h"
#include "time.h"
#include "gtest/gtest.h"
#include <iostream>

TEST(ut_0005_palindrome, test0) {
  Palindrome().longestPalindrome("ababb");
  Palindrome().longestPalindrome("");
  Palindrome().longestPalindrome("a");
  Palindrome().longestPalindrome("aa");
  Palindrome().longestPalindrome("aab");
  Palindrome().longestPalindrome("aabbccbb");
  Palindrome().longestPalindrome("abcddc");
  Palindrome().longestPalindrome3("abcba");
  Palindrome().longestPalindrome3("abccba");
  Palindrome().longestPalindrome3("aidafjkdlfadbccba");
  Palindrome().longestPalindrome3("abccba");
  Palindrome().longestPalindrome3("abccba");
  Palindrome().longestPalindrome3("cbb");

  clock_t start, stop;
  start = clock();
  Palindrome().longestPalindrome(
      "vaomxdtiuwqlwhgutkhxxhccsgvyoaccuicgybnqnslogtqhblegfudagpxfvjdacsxgevve"
      "puwthdtybgflsxjdmmfumyqgpxatvdypjmlapccaxwkuxkilqqgpihyepkilhlfkdrbsefin"
      "itdcaghqmhylnixidrygdnzmgubeybczjceiybowglkywrpkfcwpsjbkcpnvfbxnpuqzhotz"
      "spgebptnhwevbkcueyzecdrjpbpxemagnwmtwikmkpqluwmvyswvxghajknjxfazshsvjkst"
      "kezdlbnkwxawlwkqnxghjzyigkvqpapvsntojnxlmtywdrommoltpbvxwqyijpkirvndwpgu"
      "fgjelqvwffpuycqfwenhzrbzbdtupyutgccdjyvhptnuhxdwbmdcbpfvxvtfryszhaakwshr"
      "jseonfvjrrdefyxefqfvadlwmedpvnozobftnnsutegrtxhwitrwdpfienhdbvvykoynrsbp"
      "mzjtotjxbvemgoxreiveakmmbbvbmfbbnyfxwrueswdlxvuelbkrdxlutyukppkzjnmfmclq"
      "pkwzyylwlzsvriwomchzzqwqglpflaepoxcnnewzstvegyaowwhgvcwjhbbstvzhhvghigoa"
      "zbjiikglbqlxlccrwqvyqxpbtpoqjliziwmdkzfsrqtqdkeniulsavsfqsjwnvpprvczcuji"
      "hoqeanobhlsvbzmgflhykndfydbxatskf");
  stop = clock();
  cout << "long_palindrome use time: " << stop - start << endl;
  start = clock();
  Palindrome().longestPalindrome2(
      "vaomxdtiuwqlwhgutkhxxhccsgvyoaccuicgybnqnslogtqhblegfudagpxfvjdacsxgevve"
      "puwthdtybgflsxjdmmfumyqgpxatvdypjmlapccaxwkuxkilqqgpihyepkilhlfkdrbsefin"
      "itdcaghqmhylnixidrygdnzmgubeybczjceiybowglkywrpkfcwpsjbkcpnvfbxnpuqzhotz"
      "spgebptnhwevbkcueyzecdrjpbpxemagnwmtwikmkpqluwmvyswvxghajknjxfazshsvjkst"
      "kezdlbnkwxawlwkqnxghjzyigkvqpapvsntojnxlmtywdrommoltpbvxwqyijpkirvndwpgu"
      "fgjelqvwffpuycqfwenhzrbzbdtupyutgccdjyvhptnuhxdwbmdcbpfvxvtfryszhaakwshr"
      "jseonfvjrrdefyxefqfvadlwmedpvnozobftnnsutegrtxhwitrwdpfienhdbvvykoynrsbp"
      "mzjtotjxbvemgoxreiveakmmbbvbmfbbnyfxwrueswdlxvuelbkrdxlutyukppkzjnmfmclq"
      "pkwzyylwlzsvriwomchzzqwqglpflaepoxcnnewzstvegyaowwhgvcwjhbbstvzhhvghigoa"
      "zbjiikglbqlxlccrwqvyqxpbtpoqjliziwmdkzfsrqtqdkeniulsavsfqsjwnvpprvczcuji"
      "hoqeanobhlsvbzmgflhykndfydbxatskf");
  Palindrome().longestPalindrome2("aabccbfff");
  stop = clock();
  cout << "long_palindrome use time: " << stop - start << endl;
  start = clock();
  Palindrome().longestPalindrome3(
      "vaomxdtiuwqlwhgutkhxxhccsgvyoaccuicgybnqnslogtqhblegfudagpxfvjdacsxgevve"
      "puwthdtybgflsxjdmmfumyqgpxatvdypjmlapccaxwkuxkilqqgpihyepkilhlfkdrbsefin"
      "itdcaghqmhylnixidrygdnzmgubeybczjceiybowglkywrpkfcwpsjbkcpnvfbxnpuqzhotz"
      "spgebptnhwevbkcueyzecdrjpbpxemagnwmtwikmkpqluwmvyswvxghajknjxfazshsvjkst"
      "kezdlbnkwxawlwkqnxghjzyigkvqpapvsntojnxlmtywdrommoltpbvxwqyijpkirvndwpgu"
      "fgjelqvwffpuycqfwenhzrbzbdtupyutgccdjyvhptnuhxdwbmdcbpfvxvtfryszhaakwshr"
      "jseonfvjrrdefyxefqfvadlwmedpvnozobftnnsutegrtxhwitrwdpfienhdbvvykoynrsbp"
      "mzjtotjxbvemgoxreiveakmmbbvbmfbbnyfxwrueswdlxvuelbkrdxlutyukppkzjnmfmclq"
      "pkwzyylwlzsvriwomchzzqwqglpflaepoxcnnewzstvegyaowwhgvcwjhbbstvzhhvghigoa"
      "zbjiikglbqlxlccrwqvyqxpbtpoqjliziwmdkzfsrqtqdkeniulsavsfqsjwnvpprvczcuji"
      "hoqeanobhlsvbzmgflhykndfydbxatskf");
  stop = clock();
  cout << "long_palindrome use time: " << stop - start << endl;
}
int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
