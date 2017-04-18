#include <vector>
#include <string>
#include "Node.h"
using namespace std;

class Solution 
{
public:
  Solution()
  {
      this->minEndNodeDepth = -1;
  }
  vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) 
  {
    this->minEndNodeDepth = wordList.size();
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
    root->_printAll();
    for(int i = 0; i<endNode.size(); i++)
    {
        vector<string> v_tmp;
        Node* t_it = endNode[i];
        v_tmp.insert( v_tmp.begin(), t_it->_data() );
        while(t_it->_father() != NULL)
        {
            t_it = t_it->_father();
            v_tmp.insert( v_tmp.begin(), t_it->_data() );
        }
        result.push_back(v_tmp);
    }
    for(vector<vector<string>>::iterator iter = result.begin(); iter!=result.end(); )
    {
        if(iter->size() - 1 == this->minEndNodeDepth )
            iter++;
        else
            result.erase(iter);
    }

    return result;
  }
  void BuildTree(Node* node, vector<Node*>& endNode, string endWord, vector<string>& wordList)
  {
    for(vector<string>::iterator iter = wordList.begin(); iter != wordList.end(); iter++)
    {
      Node* t = new Node(*iter); 
      if( this->Diff(*iter, node->_data()) != 1)
        continue;
      else if ( *iter == endWord)
      {
        Node* t_it = node;
        while(t_it->_father() != NULL)
        {
            if ( t_it->_father()->_data() == *iter )
            {
                return;
            }
            t_it = t_it->_father();
        }
        node->_addChild(t);
        if(t->_depth() <= this->minEndNodeDepth)
        {
            this->minEndNodeDepth = t->_depth();
            endNode.push_back(t);
        }
        continue;
      }
      else
      {
        node->_addChild(t);
      }
      if(t->_depth() > wordList.size())
      {
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

  int minEndNodeDepth;
};
