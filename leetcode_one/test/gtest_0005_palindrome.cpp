#include "gtest/gtest.h"
#include "0005_palindrome/palindrome.h"
#include "time.h"
#include <iostream>

int main() {
  Solution su;
  su.longestPalindrome("ababb");
  su.longestPalindrome("");
  su.longestPalindrome("a");
  su.longestPalindrome("aa");
  su.longestPalindrome("aab");
  su.longestPalindrome("aabbccbb");
  su.longestPalindrome("abcddc");
  clock_t start, stop;
  start = clock();
  su.longestPalindrome(
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
  cout << "1: " << stop - start << endl;
  start = clock();
  su.longestPalindrome2(
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
  su.longestPalindrome2("aabccbfff");
  stop = clock();
  cout << "2: " << stop - start << endl;
  su.longestPalindrome3("abcba");
  su.longestPalindrome3("abccba");
  su.longestPalindrome3("aidafjkdlfadbccba");
  su.longestPalindrome3("abccba");
  su.longestPalindrome3("abccba");
  start = clock();
  su.longestPalindrome3(
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
  cout << "3: " << stop - start << endl;
  cout << "----------------------------------" << endl;
  cout << su.longestPalindrome3("cbb") << endl;
  return 0;
}
