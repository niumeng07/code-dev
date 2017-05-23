#include <iostream>
#include "Solution.h"
//#include "Solution2.h"
using namespace std;
int main()
{
  //vector<string> vec({"hot","dot","dog","lot","log","cog"});
  vector<string> vec({"hot","dot","dog","lot","log"});
  string beginWord = "hit";
  string endWord = "cog";

  vector<string> vec2({"ts","sc","ph","ca","jr","hf","to","if","ha","is","io","cf","ta"});
  string beginWord2 = "ta";
  string endWord2 = "if";
  Solution su;
  vector<vector<string>> result = su.findLadders(beginWord, endWord, vec);
  vector<vector<string>> result2 = su.findLadders(beginWord2, endWord2, vec2);
  for(auto xx : result2)
  {
      for( auto x : xx)
          cout << x << "\t" << ends;
      cout << endl;
  }
  return 0;
}
