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
      //添加diff ==1逻辑
      Node* t = new Node(*iter); 
      node->_addChild(t);
      if(endWord == *iter)
      {
        cout << endWord << "  " << *iter << endl;
        this->find = true;
        endNode.push_back(t);
        return;
      }
    }
    for(int i  = 0; i< node->_childNum(); i++)
    {
      this->BuildTree(node->_getChildNode(i), endNode, endWord, wordList);
    }
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
