/*

easy

*/
#include <string>
#include <map>
using namespace std;
class Solution {
public:
    int romanToInt(string s) {
        map<char, int> m = map<char, int>();
        int value = 0;
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;
        for (int i = 0; i < s.length(); i++) {
            switch (s[i]) {
                case 'I':
                case 'X':
                case 'C':
                {
                    if (i + 1 < s.length() && m[s[i + 1]] > m[s[i]]) {
                        value += m[s[i + 1]] - m[s[i]];
                        i++;
                        break;
                    }
                }
                default:
                {
                    value += m[s[i]];
                }
            }
        }
        return value;
    }
};