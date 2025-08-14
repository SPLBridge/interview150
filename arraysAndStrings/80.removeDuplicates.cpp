/*

medium

*/
#include <vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int numsLength = nums.size();
        if (numsLength < 2) {
            return numsLength;
        }
        int cur = 2;
        for (int i = 2; i < numsLength; i++) {
            if (nums[i] != nums[cur - 2]) {
                nums[cur++] = nums[i];
            }
        }
        return cur;
    }
};