#include <iostream>

#include "0072_edit_distance/edit_distance.h"
#include "gtest/gtest.h"
using namespace std;
int main(int argc, char **argv) {
    cout << Solution().minDistance("zoologicoarchaeologist", "zoogeologist")
         << endl;
    cout << Solution().minDistance("horse", "ros") << endl;
    // cout << Solution().minDistance("abc", "abd") << endl;
    // cout << Solution().minDistance("abc", "abc") << endl;
    // cout << Solution().minDistance("", "abc") << endl;
    // cout << Solution().minDistance("", "") << endl;
    return 0;
}


/*
     z  o  o  g  e  o  l  o  g  i  s  t
  0  1  2  3  4  5  6  7  8  9  10 11 12
z 1  0  1  2  3  4  5  6  7  8  9  10 11
o 2  1  0  0  1  2  2  3  3  4  5  6  7 
o 3  2  0  0  1  2  2  3  3  4  5  6  7 
l 4  3  1  1  1  2  3  2  3  4  5  6  7 
o 5  4  1  1  2  2  2  3  2  3  4  5  6 
g 6  5  2  2  1  2  3  3  3  2  3  4  5 
i 7  6  3  3  2  2  3  4  4  3  2  3  4 
c 8  7  4  4  3  3  3  4  5  4  3  3  4 
o 9  8  4  4  4  4  3  4  4  5  4  4  4 
a 10 9  5  5  5  5  4  4  5  5  5  5  5 
r 11 10 6  6  6  6  5  5  5  6  6  6  6 
c 12 11 7  7  7  7  6  6  6  6  7  7  7 
h 13 12 8  8  8  8  7  7  7  7  7  8  8 
a 14 13 9  9  9  9  8  8  8  8  8  8  9 
e 15 14 10 10 10 9  9  9  9  9  9  9  9 
o 16 15 10 10 11 10 9  10 9  10 10 10 10
l 17 16 11 11 11 11 10 9  10 10 11 11 11
o 18 17 11 11 12 12 10 10 9  10 11 12 12
g 19 18 12 12 11 12 11 11 10 9  10 11 12
i 20 19 13 13 12 12 12 12 11 10 9  10 11
s 21 20 14 14 13 13 13 13 12 11 10 9  10
t 22 21 15 15 14 14 14 14 13 12 11 10 9 
*/
