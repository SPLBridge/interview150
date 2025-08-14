#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) {
            return "";
        }

        string prefix = "";
        for (int i = 0; i < strs[0].size(); i++) {
            char cur = strs[0][i];
            for (int j = 1; j < strs.size(); j++) {
                if (i >= strs[j].size() || strs[j][i] != cur) {
                    return prefix;
                }
            }
            prefix += cur;
        }
        return prefix;
    }
};