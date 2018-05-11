Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

Example:

Input: "aab"
Output: 1
Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.


// DP
// Reference solution:
// 从后往前更新一维dp数组，dp[i]表示从下标i~n-1所需的最小切割数。
// 初始化dp数组为：dp[i] = len-i-1, i = 0~n-1;
// 递推公式：
// dp[i] = min(dp[i], 1+dp[j+1]), 其中i<=j<n
// 但上式能够这么算还需一个条件，就是i~j之间的子字符串需构成回文，为此可以维护另一个二维dp数组P来简化判断过程，
// P[i][j]表示下标从i~j的子字符串是否构成回文，首先将其每个值都初始化为false， 递推公式如下：
// P[i][j] = true, if (s[i] == s[j] && (j-i<=1 || P[i+1][j-1])), i<=j<n

class Solution {
public:
    int minCut(string s) {
        int len = s.size();
        bool P[len][len];
        int dp[len + 1];
        for (int i = 0; i <= len; ++i) {
            dp[i] = len - i - 1;
        }
        for (int i = 0; i < len; ++i) {
            for (int j = 0; j < len; ++j) {
                P[i][j] = false;
            }
        }
        for (int i = len - 1; i >= 0; --i) {
            for (int j = i; j < len; ++j) {
                if (s[i] == s[j] && (j - i <= 1 || P[i + 1][j - 1])) {
                    P[i][j] = true;
                    dp[i] = min(dp[i], dp[j + 1] + 1);
                }
            }
        }
        return dp[0];
    }
};