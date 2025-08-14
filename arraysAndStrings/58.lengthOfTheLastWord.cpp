#include <string>
using namespace std;
class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = 0;
        int i = s.size() - 1;
        for (;s[i] == ' '; i--);
        for (; i >= 0 && s[i] != ' '; i--) {
            length++;
        }
        return length;
    }
};