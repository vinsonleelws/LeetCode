Given a string S and a string T, count the number of distinct subsequences of S which equals T.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Example 1:

Input: S = "rabbbit", T = "rabbit"
Output: 3
Explanation:

As shown below, there are 3 ways you can generate "rabbit" from S.
(The caret symbol ^ means the chosen letters)

rabbbit
^^^^ ^^
rabbbit
^^ ^^^^
rabbbit
^^^ ^^^

Example 2:

Input: S = "babgbag", T = "bag"
Output: 5
Explanation:

As shown below, there are 5 ways you can generate "bag" from S.
(The caret symbol ^ means the chosen letters)

babgbag
^^ ^
babgbag
^^    ^
babgbag
^    ^^
babgbag
  ^  ^^
babgbag
    ^^^

// DP
// d[i][j]: T从头到下标为j-1的子字符串可以从S从头到下标为i-1的自字符串产生出的次数。
// 手动写出二维dp数组分析其规律：
//   Ø r a b b b i t (T)
// Ø 1 1 1 1 1 1 1 1
// r 0 1 1 1 1 1 1 1
// a 0 0 1 1 1 1 1 1
// b 0 0 0 1 2 3 3 3
// b 0 0 0 0 1 3 3 3
// i 0 0 0 0 0 0 3 3
// t 0 0 0 0 0 0 0 3 
//(S)
  
// 递推公式：
// 1) 初始化： dp[0][i] = 1 , dp[i][0] = 0;
// 2) dp[i][j] = dp[i][j-1] + (T[i-1]==S[j-1]? dp[i-1][j-1] : 0)

class Solution {
public:
    int numDistinct(string S, string T) {
        int dp[T.size() + 1][S.size() + 1];
        
        for (int i = 0; i <= S.size(); ++i) 
            dp[0][i] = 1;    
        for (int i = 1; i <= T.size(); ++i) 
            dp[i][0] = 0;    
        
        for (int i = 1; i <= T.size(); ++i) 
            for (int j = 1; j <= S.size(); ++j) 
                dp[i][j] = dp[i][j - 1] + (T[i - 1] == S[j - 1] ? dp[i - 1][j - 1] : 0);
            
        return dp[T.size()][S.size()];
    }
};

// Trick:
// 有关字符串的子序列或者配准类的问题，首先考虑用动态规划Dynamic Programming来求解。