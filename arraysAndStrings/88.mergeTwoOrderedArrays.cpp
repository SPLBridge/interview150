/*

Easy

*/
#include <vector>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> nums = vector<int>(m + n, 0);
        for (int i = 0, p1 = 0, p2 = 0; i < m + n; i++) {
            if (p1 == m) {
                for (; p2 < n; p2++, i++) {
                    nums[i] = nums2[p2];
                }
                break;
            }
            if (p2 == n) {
                for (; p1 < m; p1++, i++) {
                    nums[i] = nums1[p1];
                }
                break;
            }
            if (nums1[p1] <= nums2[p2]) {
                nums[i] = nums1[p1++];
            } else {
                nums[i] = nums2[p2++];
            }
        }
        swap(nums1, nums);
    }
};

int main() {
    vector<int> nums1 = vector<int>(6, 0);
    vector<int> nums2 = vector<int>(3, 0);
    nums1[0] = 1;
    nums1[1] = 2;
    nums1[2] = 3;
    nums2[0] = 2;
    nums2[1] = 5;
    nums2[2] = 6;
    Solution s = Solution();
    s.merge(nums1, 3, nums2, 3);
}