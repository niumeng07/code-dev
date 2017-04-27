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
        vector<Node*> leafNode;
        leafNode.push_back(root);
        this->BuildTree(root, leafNode, endWord, wordList);
        //root->_printAll();

        for(int i = 0; i < leafNode.size(); i++)
        {
            if( leafNode[i]->_data() == endWord)
            {
                vector<string> unit;
                Node* tmp = leafNode[i];
                while(tmp != NULL)
                {
                    unit.insert(unit.begin(), tmp->_data());
                    tmp = tmp->_father();
                }
                result.push_back(unit);
            }
        }
        return result;
    }
    void BuildTree(Node* node, vector<Node*>& leafNode, string endWord, vector<string>& wordList)
    {
        int leafOldSize = leafNode.size();
        bool found = false;
        for ( int i = 0; i< leafOldSize; i++)
        {
            for( auto word : wordList)
            {
                if(this->Diff(word, (leafNode[i])->_data()) == 1 )
                {
                    if(word == endWord) found = true;

                    Node *t = new Node(word);
                    (leafNode[i])->_addChild(t);
                    leafNode.push_back(t);
                }
            }
        }
        if(found) return;
        for(int i = 0; i<leafOldSize; i++)
            leafNode.erase(leafNode.begin());

        this->BuildTree(node, leafNode, endWord, wordList);
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

};
