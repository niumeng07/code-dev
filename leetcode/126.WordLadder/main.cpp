#include <iostream>
#include "Solution.h"
using namespace std;
int main()
{
  //["hot","dot","dog","lot","log","cog"]
  //hit
  //cog
  vector<string> vec({"hot","dot","dog","lot","log","cog"});
  string beginWord = "hit";
  string endWord = "cog";
  Solution su;
  su.findLadders(beginWord, endWord, vec);
  return 0;
}

