/*
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Note that you cannot sell a stock before you buy one.

Example 1:

Input: [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
             Not 7-1 = 6, as selling price needs to be larger than buying price.

Example 2:

Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
 */


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
    }
};

// 买卖股票的最佳时间（限制只买入和卖出一次）  [E]
// Greedy

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.empty() || prices.size() == 1)
			return 0;

		int result = 0, low = prices[0];
		for (int i = 0; i < prices.size(); i++)
		{
			if (prices[i] > low && prices[i] - low > result)
				result = prices[i] - low;
			else if (prices[i] < low)
				low = prices[i];
		}

		return result;
	}
};

// 另一种写法
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int res = 0, buy = INT_MAX;
		for (int price : prices)
		{
			buy = min(buy, price);
			res = max(res, price - buy);
		}
		return res;
	}
};