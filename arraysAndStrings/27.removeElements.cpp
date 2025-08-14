/*

Easy

*/
#include <vector>
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int length = nums.size();
        int k = length;
        vector<int> removedNums = vector<int>(length);
        for (int i = 0, cur = 0; i < length; i++) {
            if (nums[i] == val) {
                k--;
            } else {
                removedNums[cur++] = nums[i];
            }
        }
        swap(nums, removedNums);
        return k;
    }
};