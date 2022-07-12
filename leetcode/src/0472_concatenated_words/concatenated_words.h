#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Trie {
    bool isEnd;
    vector<Trie *> children;
    Trie() {
        this->children = vector<Trie *>(26, nullptr);
        this->isEnd = false;
    }
};

class Solution {
public:
    Trie *trie = new Trie();

    vector<string> findAllConcatenatedWordsInADict(vector<string> &words) {
        vector<string> ans;
        sort(words.begin(), words.end(), [&](const string &a, const string &b) {
            return a.size() < b.size();
        });
        for (int i = 0; i < words.size(); i++) {
            string word = words[i];
            if (word.size() == 0) {
                continue;
            }
            vector<int> visited(word.size(), 0);
            if (dfs(word, 0, visited)) {
                ans.emplace_back(word);
            } else {
                insert(word);
            }
        }
        return ans;
    }

    bool dfs(const string &word, int start, vector<int> &visited) {
        if (word.size() == start) {
            return true;
        }
        if (visited[start]) {
            return false;
        }
        visited[start] = true;
        Trie *node = trie;
        for (int i = start; i < word.size(); i++) {
            char ch = word[i];
            int index = ch - 'a';
            node = node->children[index];
            if (node == nullptr) {
                return false;
            }
            if (node->isEnd) {
                if (dfs(word, i + 1, visited)) {
                    return true;
                }
            }
        }
        return false;
    }

    void insert(const string &word) {
        Trie *node = trie;
        for (int i = 0; i < word.size(); i++) {
            char ch = word[i];
            int index = ch - 'a';
            if (node->children[index] == nullptr) {
                node->children[index] = new Trie();
            }
            node = node->children[index];
        }
        node->isEnd = true;
    }
};
