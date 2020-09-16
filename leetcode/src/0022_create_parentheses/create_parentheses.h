/**
 * @brief
 * Given n pairs of parentheses, write a function to generate all combinations
 * of well-formed parentheses.
 *
 * For example, given n = 3, a solution set is:
 *
 * [
 *   "((()))",
 *   "(()())",
 *   "(())()",
 *   "()(())",
 *   "()()()"
 * ]
 * Subscribe to see which companies asked this question.
 *
 */
#include <string>
#include <vector>

using namespace std;

class CreateParentheses {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        this->generate(ret, 0, 0, n, "");
        return ret;
    }

private:
    void generate(vector<string> &ret, int left, int right, int n, string s);
};

void CreateParentheses::generate(vector<string> &ret, int left, int right,
                                 int n, string s) {
    if (left == n && left == right) ret.emplace_back(s);
    if (left == n && left != right)
        this->generate(ret, left, right + 1, n, s + ")");

    if (left < n && left == right)
        this->generate(ret, left + 1, right, n, s + "(");
    if (left < n && left != right) {
        this->generate(ret, left + 1, right, n, s + "(");
        this->generate(ret, left, right + 1, n, s + ")");
    }
    return;
}
