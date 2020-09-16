#include <iostream>

#include "0005_palindrome/palindrome.h"
#include "gtest/gtest.h"
#include "time.h"

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
            "vaomxdtiuwqlwhgutkhxxhccsgvyoaccuicgybnqnslogtqhblegfudagpxfvjdacs"
            "xgevve"
            "puwthdtybgflsxjdmmfumyqgpxatvdypjmlapccaxwkuxkilqqgpihyepkilhlfkdr"
            "bsefin"
            "itdcaghqmhylnixidrygdnzmgubeybczjceiybowglkywrpkfcwpsjbkcpnvfbxnpu"
            "qzhotz"
            "spgebptnhwevbkcueyzecdrjpbpxemagnwmtwikmkpqluwmvyswvxghajknjxfazsh"
            "svjkst"
            "kezdlbnkwxawlwkqnxghjzyigkvqpapvsntojnxlmtywdrommoltpbvxwqyijpkirv"
            "ndwpgu"
            "fgjelqvwffpuycqfwenhzrbzbdtupyutgccdjyvhptnuhxdwbmdcbpfvxvtfryszha"
            "akwshr"
            "jseonfvjrrdefyxefqfvadlwmedpvnozobftnnsutegrtxhwitrwdpfienhdbvvyko"
            "ynrsbp"
            "mzjtotjxbvemgoxreiveakmmbbvbmfbbnyfxwrueswdlxvuelbkrdxlutyukppkzjn"
            "mfmclq"
            "pkwzyylwlzsvriwomchzzqwqglpflaepoxcnnewzstvegyaowwhgvcwjhbbstvzhhv"
            "ghigoa"
            "zbjiikglbqlxlccrwqvyqxpbtpoqjliziwmdkzfsrqtqdkeniulsavsfqsjwnvpprv"
            "czcuji"
            "hoqeanobhlsvbzmgflhykndfydbxatskf");
    stop = clock();
    cout << "long_palindrome use time: " << stop - start << endl;
    start = clock();
    Palindrome().longestPalindrome2(
            "vaomxdtiuwqlwhgutkhxxhccsgvyoaccuicgybnqnslogtqhblegfudagpxfvjdacs"
            "xgevve"
            "puwthdtybgflsxjdmmfumyqgpxatvdypjmlapccaxwkuxkilqqgpihyepkilhlfkdr"
            "bsefin"
            "itdcaghqmhylnixidrygdnzmgubeybczjceiybowglkywrpkfcwpsjbkcpnvfbxnpu"
            "qzhotz"
            "spgebptnhwevbkcueyzecdrjpbpxemagnwmtwikmkpqluwmvyswvxghajknjxfazsh"
            "svjkst"
            "kezdlbnkwxawlwkqnxghjzyigkvqpapvsntojnxlmtywdrommoltpbvxwqyijpkirv"
            "ndwpgu"
            "fgjelqvwffpuycqfwenhzrbzbdtupyutgccdjyvhptnuhxdwbmdcbpfvxvtfryszha"
            "akwshr"
            "jseonfvjrrdefyxefqfvadlwmedpvnozobftnnsutegrtxhwitrwdpfienhdbvvyko"
            "ynrsbp"
            "mzjtotjxbvemgoxreiveakmmbbvbmfbbnyfxwrueswdlxvuelbkrdxlutyukppkzjn"
            "mfmclq"
            "pkwzyylwlzsvriwomchzzqwqglpflaepoxcnnewzstvegyaowwhgvcwjhbbstvzhhv"
            "ghigoa"
            "zbjiikglbqlxlccrwqvyqxpbtpoqjliziwmdkzfsrqtqdkeniulsavsfqsjwnvpprv"
            "czcuji"
            "hoqeanobhlsvbzmgflhykndfydbxatskf");
    Palindrome().longestPalindrome2("aabccbfff");
    stop = clock();
    cout << "long_palindrome use time: " << stop - start << endl;
    start = clock();
    Palindrome().longestPalindrome3(
            "vaomxdtiuwqlwhgutkhxxhccsgvyoaccuicgybnqnslogtqhblegfudagpxfvjdacs"
            "xgevve"
            "puwthdtybgflsxjdmmfumyqgpxatvdypjmlapccaxwkuxkilqqgpihyepkilhlfkdr"
            "bsefin"
            "itdcaghqmhylnixidrygdnzmgubeybczjceiybowglkywrpkfcwpsjbkcpnvfbxnpu"
            "qzhotz"
            "spgebptnhwevbkcueyzecdrjpbpxemagnwmtwikmkpqluwmvyswvxghajknjxfazsh"
            "svjkst"
            "kezdlbnkwxawlwkqnxghjzyigkvqpapvsntojnxlmtywdrommoltpbvxwqyijpkirv"
            "ndwpgu"
            "fgjelqvwffpuycqfwenhzrbzbdtupyutgccdjyvhptnuhxdwbmdcbpfvxvtfryszha"
            "akwshr"
            "jseonfvjrrdefyxefqfvadlwmedpvnozobftnnsutegrtxhwitrwdpfienhdbvvyko"
            "ynrsbp"
            "mzjtotjxbvemgoxreiveakmmbbvbmfbbnyfxwrueswdlxvuelbkrdxlutyukppkzjn"
            "mfmclq"
            "pkwzyylwlzsvriwomchzzqwqglpflaepoxcnnewzstvegyaowwhgvcwjhbbstvzhhv"
            "ghigoa"
            "zbjiikglbqlxlccrwqvyqxpbtpoqjliziwmdkzfsrqtqdkeniulsavsfqsjwnvpprv"
            "czcuji"
            "hoqeanobhlsvbzmgflhykndfydbxatskf");
    stop = clock();
    cout << "long_palindrome use time: " << stop - start << endl;
}
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
