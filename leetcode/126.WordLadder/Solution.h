#include <vector>
#include <string>
#include "Node.h"
using namespace std;

class Solution 
{
public:
  vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) 
  {
    vector<vector<string>> result;
    if(beginWord == endWord)
    {
      vector<string> tmp({beginWord});
      result.push_back(tmp);
      return result;
    }
    Node* root = new Node(beginWord);
    vector<Node*> endNode;
    this->BuildTree(root, endNode, endWord, wordList);
    cout << "printAll()" << endl;
    root->_printAll();
  }
  void BuildTree(Node* node, vector<Node*>& endNode, string endWord, vector<string>& wordList)
  {
    for(vector<string>::iterator iter = wordList.begin(); iter != wordList.end(); iter++)
    {
      //cout << this->Diff(endWord, *iter) << endl;
      Node* t = new Node(*iter); 
      // 当前Node的data, 即*iter
      //   与father, 即node差异不为1, continue
      if( this->Diff(*iter, node->_data()) != 1)
      { 
        continue;
      }
      //   与father差异为1, 与endWord相同,push到Tree中并加到endNode
      else if ( *iter == endWord)
      {
        node->_addChild(t);
        //endNode.push_back(t);
      }
      //   与father差异为1, 与endWord不同,push到Tree中
      else
      {
        //node->_addChild(t);
      }
    }
    for(int i  = 0; i< node->_childNum(); i++)
    {
      this->BuildTree(node->_getChildNode(i), endNode, endWord, wordList);
    }
    // 从endNode中反向
  }
  int Diff(string s1, string s2)
  {
    if(s1.size() != s2.size()) return - 1;
    int diff = 0;
    for(int i = 0; i < s1.size(); i++)
    {
      if(s1[i] != s2[i])
        diff++;
    }
    return diff;
  }

  bool find = false;
};
