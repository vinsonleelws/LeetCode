/* A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

Note: m and n will be at most 100.

Example 1:

Input:
[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
Output: 2
Explanation:
There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right
 */
 
// 63-不同的路径数II(有障碍物)
// DP

// 使用动态规划，当遇到为1的点，将该位置的dp数组中的值清零；
// 需注意的特殊情况：障碍物在原点的时候，直接返回0，否则置dp[0]=1.

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.empty() || obstacleGrid[0].empty() || obstacleGrid[0][0] == 1)  // 注意障碍物在原点的情况
            return 0;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<int> dp(n, 0);
        dp[0] = 1; // 原点初始化为1
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
            {
                if(obstacleGrid[i][j]==1)
                    dp[j] = 0;
                else if(j>0)  // 注意是j>0
                    dp[j] += dp[j - 1]; 
            }
            
        return dp[n - 1];
        
    }
};