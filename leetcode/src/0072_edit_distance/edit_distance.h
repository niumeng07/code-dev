#include <string>
#include <vector>
using namespace std;

void printMatrix(const vector<vector<int> >& matrix) {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            cout << matrix[i][j] << ", ";
        }
        cout << endl;
    }
    cout << "-----------------------------" << endl;
}

class Solution {
public:
    int min(int& a, int& b, int& c) { return std::min(std::min(a, b), c); }
    int minDistance(string word1, string word2) {
        if (word1.empty()) return word2.size();
        if (word2.empty()) return word1.size();
        int size1 = word1.size() + 1;
        int size2 = word2.size() + 1;
        vector<vector<int> > matrix(size1, vector<int>(size2, 0));
        for (int i = 0; i < size1; i++) {
            matrix[i][0] = i;
        }
        for (int j = 0; j < size2; j++) {
            matrix[0][j] = j;
        }
        // printMatrix(matrix);
        for (int i = 1; i < size1; i++) {
            for (int j = 1; j < size2; j++) {
                if (word1[i - 1] != word2[j - 1]) {
                    matrix[i][j] =
                            1 + this->min(matrix[i - 1][j], matrix[i][j - 1],
                                          matrix[i - 1][j - 1]);
                } else {
                    matrix[i][j] = matrix[i - 1][j - 1];
                }
            }
        }
        // printMatrix(matrix);
        return matrix[size1 - 1][size2 - 1];
    }
};
