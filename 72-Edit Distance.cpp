Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.

You have the following 3 operations permitted on a word:

    Insert a character
    Delete a character
    Replace a character

Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')

Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')


// Reference solution:
// 思路：采用动态规划
// 维护一个二维的数组dp，其中dp[i][j]表示从word1的前i个字符转换到word2的前j个字符所需要的步骤。
// 那我们可以先给这个二维数组dp的第一行第一列赋值，这个很简单，因为第一行和第一列对应的总有一个字符串是空串，
// 于是转换步骤完全是另一个字符串的长度。跟以往的DP题目类似，难点还是在于找出递推式，我们可以举个例子来看，
// 比如word1是“bbc"，word2是”abcd“，那么我们可以得到dp数组如下：

  Ø a b c d
Ø 0 1 2 3 4
b 1 1 1 2 3
b 2 2 1 2 3
c 3 3 2 1 2

// 通过观察可以发现，当word1[i] == word2[j]时，dp[i][j] = dp[i - 1][j - 1]，
// 其他情况时，dp[i][j]是其左，左上，上的三个值中的最小值加1，那么可以得到递推式为：
            /    dp[i - 1][j - 1]                                               (When word1[i - 1] == word2[j - 1])
dp[i][j] =
            \    min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1     (Otherwise)
                
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();
        int dp[n1 + 1][n2 + 1]={0};
        for (int i=0; i<=n1; ++i) 
            dp[i][0] = i;
        for (int j=1; j<=n2; ++j) 
            dp[0][j] = j;
        for (int i=1; i<=n1; ++i) 
        {
            for (int j=1; j<=n2; ++j) 
            {
                if (word1[i-1] == word2[j-1]) 
                    dp[i][j] = dp[i-1][j-1];
                else 
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
            }
        }
        return dp[n1][n2];
    }
};

// 可以进一步优化空间，只使用两个一维数组来维护dp变量：
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();
        if(n1==0)
            return n2;
        else if(n2==0)
            return n1;
            
        int left[n1+1]={0}, up[n2+1]={0};
        for(int i=1; i<=n1; i++)
            left[i] = i;
        for(int i=1; i<=n2; i++)
            up[i] = i;
        int cur = 0;
        for (int i=1; i<=n1; ++i) 
        {
            int l = left[i];
            for (int j=1; j<=n2; ++j) 
            {
                if (word1[i-1] == word2[j-1]) 
                    cur = up[j-1];
                else 
                    cur = min(l, min(up[j], up[j-1]))+1;
                
                up[j-1] = l;
                l = cur;
            }
            up[n2] = cur;   // 注意更新up数组中的最后一个值。
        }
        return cur;
    }
};