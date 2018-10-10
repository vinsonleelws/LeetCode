/*A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26

Given a non-empty string containing only digits, determine the total number of ways to decode it.

Example 1:

Input: "12"
Output: 2
Explanation: It could be decoded as "AB" (1 2) or "L" (12).

Example 2:

Input: "226"
Output: 3
Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).

*/

class Solution {
public:
    int numDecodings(string s) {
        
    }
};


// 译码方法  [M]
// DP

// DP
// dp[i]表示i及i以前构成的字符串的译码方法数
// 递推公式：
// dp[i] = (s[i]=='0'? 0 : dp[i-1]) + g2(i-1, i)*dp[i-2];
// dp[0] = s[0]=='0'? 0 : 1;
// g(i-1, i) = 1 when 1<="s[i-1]s[i]" <=26

class Solution {
public:
	int numDecodings(string s) {
		if (s.empty())
			return 0;
		int n = s.length();
		vector<int> dp(n, 0);
		dp[0] = s[0] == '0' ? 0 : 1;
		for (int i = 1; i < n; i++)
		{
			dp[i] = s[i] == '0' ? 0 : dp[i - 1];
			if (s[i - 1] == '1' || s[i - 1] == '2' && s[i] <= '6')
			{
				if (i == 1)
					dp[1] += 1;
				else
					dp[i] += dp[i - 2];
			}
		}

		return dp[n - 1];
	}
};

// 可以进一步优化，使空间效率为O(1)
class Solution {
public:
	int numDecodings(string s) {
		if (s.empty())
			return 0;
		int n = s.length();
		int n1 = 0, n2 = 0, cur = 0;
		cur = n1 = n2 = s[0] == '0' ? 0 : 1;
		for (int i = 1; i < n; i++)
		{
			cur = s[i] == '0' ? 0 : n2;
			if (s[i - 1] == '1' || s[i - 1] == '2' && s[i] <= '6')
			{
				if (i == 1)
					cur += 1;
				else
					cur += n1;
			}
			n1 = n2;
			n2 = cur;
		}

		return cur;
	}
};

// 另一种写法
class Solution {
public:
	int numDecodings(string s) {
		if (s.empty())
			return 0;
		int n = s.length();
		vector<int> dp(n, 0);
		dp[0] = s[0] == '0' ? 0 : 1;
		if (n > 1)
		{
			dp[1] = s[1] == '0' ? 0 : dp[0];
			if (s[0] == '1' || s[0] == '2' && s[1] <= '6')
				dp[1] += 1;
		}

		for (int i = 2; i < n; i++)
		{
			dp[i] = s[i] == '0' ? 0 : dp[i - 1];
			if (s[i - 1] == '1' || s[i - 1] == '2' && s[i] <= '6')
				dp[i] += dp[i - 2];
		}

		return dp[n - 1];
	}
};