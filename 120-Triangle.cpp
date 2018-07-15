/* 
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]

The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:

Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.

 */

// [2],
// [3,4],
// [6,5,7],
// [4,1,8,3]

// 三角形从顶部到底部的最小路径和
// DP


// 更加简洁的方法是从底向上维护dp数组
// Bottom up
class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int n = triangle.size();
        vector<int> dp(triangle.back());
        for (int i = n - 2; i >= 0; --i) // 从倒数第二行开始
            for (int j = 0; j <= i; ++j) 
                dp[j] = min(dp[j], dp[j + 1]) + triangle[i][j];

        return dp[0];
    }
};


// My solution:
// Top-down
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.empty() || triangle[0].empty())
            return 0;
        
        int n = triangle.size();
        vector<int> dp(n, 0);
        dp[0] = triangle[0][0];
        int mintotal = INT_MAX;
        for(int i=1; i<n; i++)
        {
            int left = dp[0];
            dp[0] += triangle[i][0];
            for(int j=1; j<i; j++)
            {
                int tmp = dp[j];
                dp[j] = triangle[i][j] + min(left, dp[j]);
                left = tmp;
            }
            dp[i] = triangle[i][i] + left;
        }
        
        for(int i=0; i<n; i++)
            if(dp[i]<mintotal)
                mintotal = dp[i];
        
        return mintotal;
    }
};


// Testing cases:
// Input: 
  // [[-1],
   // [2,3],
 // [1,-1,-3]]
// Expected: -1