/*

Medium

*/
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // my solution runtiome O(n) memory O(n)
        /*
        
        queue<int> q = queue<int>();
        for (int i = nums.size() - 1; i >= 0; i--) {
            q.push(nums[i]);
        }
        for (int i = 0; i < k; i++) {
            q.push(q.front());
            q.pop();
        }
        for (int i = nums.size() - 1; i >= 0; i--) {
            nums[i] = q.front();
            q.pop();
        }
        
        */
        
        // reverse in place runtime O(n) memory O(1)
        /*
        
        k = k % nums.size();
        reverse(nums, 0, nums.size() - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, nums.size() - 1);
        
        */

        // circular replacement runtime O(n) memory O(1)

        k = k % nums.size();
        for (int i = 0, start = 0; i < nums.size(); start++) {
            for (int cur = (start + k) % nums.size();
                cur != start; cur = (cur + k) % nums.size()) {
                    swap(nums[start], nums[cur]);
                    i++;
            }
            i++;
        }
    }

    void reverse(vector<int>& nums, int start, int end) {
        while (start < end) {
            swap(nums[start], nums[end]);
            start++;
            end--;
        }
    }
};