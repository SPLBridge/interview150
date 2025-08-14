/*

Medium

*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int length = prices.size();
        mem = vector<vector<int*>>(length, vector<int*>(length, nullptr));
        return dp(prices, 0, length - 1);
    }
private:
    vector<vector<int*>> mem;
    int dp(vector<int>& prices, int start, int end) {
        /*
        base case: return max(0, prices[end] - prices[start]) if start == end
        others: return max(0, prices[end] - prices[start], dp(start, start + 1) + dp(start + 1, end), ...)
        */
        int baseProfit = max(0, prices[end] - prices[start]);
        if (start == end) {
            return baseProfit;
        }
        if (mem[start][end] != nullptr) {
            return *(mem[start][end]);
        }
        vector<int> subsolutions = vector<int>(end - start);
        for (int i = start + 1, j = 0; i <= end; i++, j++) {
            subsolutions[j] = dp(prices, start, i - 1) + dp(prices, i, end);
        }
        auto max_it = max_element(subsolutions.begin(), subsolutions.end());
        int solution = *max_it;
        solution = max(baseProfit, solution);
        mem[start][end] = new int(solution);
        return solution;
    }
};
int main() {
    Solution s = Solution();
    vector<int> input = {7,1,5,3,6,4};
    cout << s.maxProfit(input) << endl;
}