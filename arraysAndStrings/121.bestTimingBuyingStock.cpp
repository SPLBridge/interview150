/*

Easy

*/
#include <vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // my solution TLE
        /*
        
        int maximumProfit = 0;
        for (int i = 0; i < prices.size() - 1; i++) {
            for (int j = i + 1; j < prices.size(); j++) {
                if (prices[j] - prices[i] > maximumProfit) {
                    maximumProfit = prices[j] - prices[i];
                }
            }
        }
        return maximumProfit;
        
        */
        
        // traverse once O(n)

        int maxProfit = 0;
        int minPrice = 2 << 29;
        for (int price : prices) {
            maxProfit = max(maxProfit, price - minPrice);
            minPrice = min(minPrice, price);
        }
        return maxProfit;
    }
};