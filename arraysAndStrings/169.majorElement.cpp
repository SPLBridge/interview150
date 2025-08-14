/*

Easy

*/
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // my solution runtime O(n), memory O(n)
        /*
        
        map<int, int> metaNums = map<int, int>();
        for (int num : nums) {
            if (metaNums.find(num) == metaNums.end()) {
                metaNums[num] = 1;
            } else {
                metaNums[num]++;
            }
        }
        int length = nums.size();
        for (pair<int, int> keyValuePair : metaNums) {
            if (keyValuePair.second > length / 2) {
                return keyValuePair.first;
            }
        }
        return 0;
        
        */
        
        // randomization runtime O(n), memory O(1)
        /*
        
        while (true) {
            int candidate = nums[rand() % nums.size()];
            int count = 0;
            for (int num : nums) {
                if (num == candidate) {
                    count++;
                }
            }
            if (count > nums.size() / 2) {
                return candidate;
            }
        }
        
        */
        
        // Boyer-Moore 投票算法 runtime O(n), memory O(1)

        int candidate = nums[0];
        int count = 0;
        for (int num : nums) {
            if (num == candidate) {
                count++;
            } else if (0 == count) {
                candidate = num;
            } else {
                count--;
            }
        }
        return candidate;
    }
};