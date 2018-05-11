Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

Note:

    The same word in the dictionary may be reused multiple times in the segmentation.
    You may assume the dictionary does not contain duplicate words.

Example 1:

Input: s = "leetcode", wordDict = ["leet", "code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".

Example 2:

Input: s = "applepenapple", wordDict = ["apple", "pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
             Note that you are allowed to reuse a dictionary word.

Example 3:

Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
Output: false

// DP
// dp[i]: 从起始到下标i-1，s是否可以被切分。
// 递推式：
// dp[i] || = dp[j] && s.substr(j, i-j) for 0<=j<i
// dp[0] = 1
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if(s.empty() || wordDict.empty())
            return false;
        int n = s.length();
        vector<bool> dp(n+1, false);
        dp[0] = true;
        for(int i=0; i<n+1; i++)
        {
            for(int j=0; j<i; j++)
            {
                if(dp[j] && find(wordDict.begin(), wordDict.end(), s.substr(j, i-j))!=wordDict.end())
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};