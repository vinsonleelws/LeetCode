/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example:

Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.
 */

// 64-最小路径和  [M]
// DP

// DP
// 递推公式：dp[i][j] = grid[i][j]+ min(dp[i-1][j], dp[i][j-1])
// 可以进一步使用一维数组来节省空间：
// dp[j] = grid[i][j] + min(dp[j], dp[j-1])，其中等号右边的dp[j]表示上面的最小值，dp[j-1]左边的最小值

class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		if (grid.empty() || grid[0].empty())
			return 0;

		vector<int> dp(grid[0].size(), INT_MAX);
		dp[0] = 0;
		for (int i = 0; i < grid.size(); i++)
			for (int j = 0; j < grid[0].size(); j++)
			{
				if (j == 0)
					dp[j] += grid[i][j];  // 第一列左边没有元素，特殊处理
				else
					dp[j] = grid[i][j] + min(dp[j], dp[j - 1]);
			}

		return dp[grid[0].size() - 1];
	}
};

// 另一种写法:
class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		if (grid.empty() || grid[0].empty())
			return 0;

		int m = grid.size();
		int n = grid[0].size();
		vector<int> dp(n, 0);
		dp[0] = grid[0][0];
		for (int i = 1; i < n; i++)
			dp[i] = dp[i - 1] + grid[0][i];

		for (int i = 1; i < m; i++)
			for (int j = 0; j < n; j++)
			{
				if (j == 0)
					dp[j] += grid[i][j];
				else
					dp[j] = grid[i][j] + min(dp[j], dp[j - 1]);
			}

		return dp[n - 1];
	}
};