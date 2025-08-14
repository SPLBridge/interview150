/*

Easy

*/
#include <vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int numsLength = nums.size();
        vector<int> deletedNums = vector<int>(numsLength);
        if (numsLength == 0) {
            return 0;
        }
        deletedNums[0] = nums[0];
        int cur = 1;
        for (int i = 1; i < numsLength; i++) {
            if (nums[i] != deletedNums[cur - 1]) {
                deletedNums[cur++] = nums[i];
            }
        }
        swap(nums, deletedNums);
        return cur;
    }
};