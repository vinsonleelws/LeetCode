Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most k transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

Example 1:

Input: [2,4,1], k = 2
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.

Example 2:

Input: [3,2,6,5,0,3], k = 2
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4.
             Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.

             
// 这道题是之前 Best Time to Buy and Sell Stock III 买股票的最佳时间之三的一般情况的推广，还是需要用动态规划Dynamic programming来解
// 但这道题还有个坑：就是如果k的值远大于prices的天数，比如k是好几百万，而prices的天数就为若干天的话，上面的DP解法就非常的没有效率，
// 应该直接用Best Time to Buy and Sell Stock II 买股票的最佳时间之二的方法来求解，所以实际上这道题是之前的二和三的综合体。

class Solution {
public:
    int maxProfit(int k, vector<int> &prices) {
        if (prices.empty()) 
            return 0;
        if (k >= prices.size()) 
            return maxProfitGreedy(prices);
        int g[k + 1] = {0};
        int l[k + 1] = {0};
        for (int i = 0; i < prices.size() - 1; ++i) {
            int diff = prices[i + 1] - prices[i];
            for (int j = k; j >= 1; --j) {
                l[j] = max(g[j - 1] + max(diff, 0), l[j] + diff);
                g[j] = max(g[j], l[j]);
            }
        }
        return g[k];
    }
    
    int maxProfitGreedy(vector<int> &prices) {
        int res = 0;
        for (int i = 1; i < prices.size(); ++i) 
            if (prices[i] - prices[i - 1] > 0) 
                res += prices[i] - prices[i - 1];
        
        return res;
    }
};
