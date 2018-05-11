Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).

Example 1:

Input: [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
             Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.

Example 2:

Input: [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
             Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are
             engaging multiple transactions at the same time. You must sell before buying again.

Example 3:

Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.

//DP
// 定义local[i][j]为在到达第i天时最多可进行j次交易并且最后一次交易在最后一天卖出的最大利润，此为局部最优。
// 定义global[i][j]为在到达第i天时最多可进行j次交易的最大利润，此为全局最优。
// 递推公式：
// local[i][j] = max(global[i - 1][j - 1] + max(diff, 0), local[i - 1][j] + diff)
// global[i][j] = max(local[i][j], global[i - 1][j])

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.empty()) 
            return 0;
        int n = prices.size(), g[n][3] = {0}, l[n][3] = {0};
        for (int i = 1; i < prices.size(); ++i) 
        {
            int diff = prices[i] - prices[i - 1];
            for (int j = 1; j <= 2; ++j) 
            {
                l[i][j] = max(g[i - 1][j - 1] + max(diff, 0), l[i - 1][j] + diff);
                g[i][j] = max(l[i][j], g[i - 1][j]);
            }
        }
        return g[n - 1][2];
    }
};

// 可以进一步优化空间复杂度至O(1)
// 用一维dp数组来代替二维dp数组，由于覆盖的顺序关系，我们按交易次数从高到底更新dp数组
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.empty()) 
            return 0;
        int g[3] = {0}, l[3] = {0};
        for (int i = 0; i < prices.size() - 1; ++i) 
        {
            int diff = prices[i + 1] - prices[i];
            for (int j = 2; j >= 1; --j) 
            {
                l[j] = max(g[j - 1] + max(diff, 0), l[j] + diff);
                g[j] = max(l[j], g[j]);
            }
        }
        return g[2];
    }
};

// 我们如果假设prices数组为1, 3, 2, 9, 那么我们来看每次更新时local 和 global 的值：
// 第一天两次交易：　　　　　　第一天一次交易：

// local:　　 0 0 0 　　 　　　 local:　　 0 0 0 

// global:　　0 0 0　　　 　　 global:　　 0 0 0

// 第二天两次交易：　　　　　　第二天一次交易：

// local:　　 0 0 2 　　　　　　local:　　 0 2 2 

// global:　　0 0 2　　　　　 　global:　　0 2 2

// 第三天两次交易：　　　　　　第三天一次交易：

// local:　　 0 2 2 　　　　　　local:　　 0 1 2 

// global:　　0 2 2　　　　 　　global:　　0 2 2

// 第四天两次交易：　　　　　　第四天一次交易：

// local:　　 0 1 9 　　　　　　local:　　 0 8 9 

// global:　　0 2 9　　　　　 　global:　　0 8 9



/* 实际上递推公式可以更简化为：
// local[i][j] = max(global[i - 1][j - 1], local[i - 1][j]) + diff
// global[i][j] = max(local[i][j], global[i - 1][j]) */

// 基于以下的分析：

// 第 i 天卖第 j 支股票的话，一定是下面的一种：

// 1. 今天刚买的
// 那么 Local(i, j) = Global(i-1, j-1)
// 相当于啥都没干

// 2. 昨天买的
// 那么 Local(i, j) = Global(i-1, j-1) + diff
// 等于Global(i-1, j-1) 中的交易，加上今天干的那一票

// 3. 更早之前买的
// 那么 Local(i, j) = Local(i-1, j) + diff
// 昨天别卖了，留到今天卖

// 但其实第一种情况是不需要考虑的，因为当天买当天卖不会增加利润，完全是重复操作，这种情况可以归纳在global[i-1][j-1]中，
// 所以我们就不需要max(0, diff)了，那么由于两项都加上了diff，所以我们可以把diff抽到max的外面，所以更新后的递推公式为：
// local[i][j] = max(global[i - 1][j - 1], local[i - 1][j]) + diff
// global[i][j] = max(local[i][j], global[i - 1][j])