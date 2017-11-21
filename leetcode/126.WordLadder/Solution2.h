#include <vector>
#include <string>
using namespace std;

class Node
{
public:
    string word;
    vector<Node*> parents;
    vector<Node*> childs;
};
class Solution
{
public:
    Node* BuildTree(string begin, string end, vector<string>& wordList)
    {
    }
    vector<vector<string> > findLadders(string beginWord, string endWord, vector<string>& wordList) 
    {
        vector<vector<string> > result;
        Node* root = this->BuildTree(beginWord, endWord, wordList);
    }
};
