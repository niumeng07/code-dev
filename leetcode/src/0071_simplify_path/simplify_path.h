#include <iostream>
using namespace std;

class Solution {
public:
    string simplifyPath(string path1) {
        if (path1.empty()) return "/";
        int size = path1.size();
        while (path1[size-1] == '/') {
            path1 = path1.substr(0, size - 1);
            size = path1.size();
        }
        vector<string> paths;
        for (int i = 0; i < size;) {
            while (path1[i] == '/' && i < size) {
                i++;
            }
            int j = i + 1;
            while (path1[j] != '/' && j < size) {
                j++;
            }
            string part = path1.substr(i, j-i);
            if (part == "..") {
                if (!paths.empty()) {
                    paths.pop_back();
                }
            } else if (part == ".") {

            } else {
                paths.push_back(part);
            }
            i = j+1;
            j = i+1;
        }
        if (paths.empty()) return "/";
        std::string result = "";
        for (const auto& item : paths) {
            result += "/" + item;
        }
        return result;
    }
};
