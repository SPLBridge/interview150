/*

easy

*/
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    int strStr(string haystack, string needle) {
        vector<int> next = vector<int>(needle.size(), 0);
        for (int i = 1; i < needle.size(); i++) {
            if (needle[i] == needle[next[i - 1]]) {
                next[i] = next[i - 1] + 1;
            } else if (next[i - 1] - 1 >= 0 && needle[i] == needle[next[next[i - 1] - 1]]) {
                next[i] = next[next[i - 1] - 1] + 1;
            }
        }
        
        for (int i = 0, cur = 0; i < haystack.size();) {
            if (haystack[i] == needle[cur]) {
                i++;
                cur++;
                if (cur == needle.size()) {
                return i - cur;
                }
            } else if (cur != 0) {
                cur = next[cur - 1];
            } else {
                i++;
            }
        }
        return -1;
    }
};