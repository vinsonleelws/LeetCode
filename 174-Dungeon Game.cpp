The demons had captured the princess (P) and imprisoned her in the bottom-right corner of a dungeon. The dungeon consists of M x N rooms laid out in a 2D grid. Our valiant knight (K) was initially positioned in the top-left room and must fight his way through the dungeon to rescue the princess.

The knight has an initial health point represented by a positive integer. If at any point his health point drops to 0 or below, he dies immediately.

Some of the rooms are guarded by demons, so the knight loses health (negative integers) upon entering these rooms; other rooms are either empty (0's) or contain magic orbs that increase the knight's health (positive integers).

In order to reach the princess as quickly as possible, the knight decides to move only rightward or downward in each step.

 

Write a function to determine the knight's minimum initial health so that he is able to rescue the princess.

For example, given the dungeon below, the initial health of the knight must be at least 7 if he follows the optimal path RIGHT-> RIGHT -> DOWN -> DOWN.
-2 (K) 	-3 	3
-5 	-10 	1
10 	30 	-5 (P)

 

Note:

    The knight's health has no upper bound.
    Any room can contain threats or power-ups, even the first room the knight enters and the bottom-right room where the princess is imprisoned.

// 此题需要保证到达右下角公主房间时，国王的生命值大于等于1。
// 从左上角开始处理会发现问题比较棘手，很难找出最优路径来，但我们反过来从右下开始逆向推理，会发现问题变得简单得多。
// DP
// dp[i][j]表示从位置(i,j)出发的所需存血量。当前位置的所需血量是由下边和右边的可生存血量决定的，因为我们的目标是起始血量尽可能的少，
// 因此，当前位置的血量应由下边或右边较小的存血量决定。因此我们用较小的可生存血量去减当前房间的数字，若结果小于零，说明当前房间的数字
// 为正，存血量可以是1，若结果大于零，则当前房间数字为负，至少需要的血量也正好等于这个正值。
// 递推公式：
// dp[i][j] = max(1, min(dp[i+1][j], dp[i][j+1])-dungeon[i][j]);
// 为了更好的处理边界情况，我们的二维dp数组比原数组的行数列数均多1个，先都初始化为整型数最大值INT_MAX，由于我们知道到达公主房间后，骑士火拼完的血量至少为1，
// 那么此时公主房间的右边和下边房间里的数字我们就都设置为1，这样到达公主房间的生存血量就是1减去公主房间的数字和1相比较，取较大值。
// 边界值设置：
// dp[m][n - 1] = 1; dp[m - 1][n] = 1;
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        if(dungeon.empty() || dungeon[0].empty())
            return 0;
        int m = dungeon.size(), n = dungeon[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, INT_MAX));
        dp[m][n - 1] = 1; dp[m - 1][n] = 1;
        for (int i = m - 1; i >= 0; --i) 
            for (int j = n - 1; j >= 0; --j) 
                dp[i][j] = max(1, min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j]);
            
        return dp[0][0];
    }
};

// 可以对空间进行优化，使用一个一维的dp数组，并且不停的覆盖原有的值
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size(), n = dungeon[0].size();
        vector<int> dp(n + 1, INT_MAX);
        dp[n - 1] = 1;
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                dp[j] = max(1, min(dp[j], dp[j + 1]) - dungeon[i][j]);
            }
        }
        return dp[0];
    }
};