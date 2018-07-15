/*Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.

Example 2:

Input: "cbbd"
Output: "bb"
*/

class Solution {
public:
    string longestPalindrome(string s) {
        
    }
};

// 最长回文串
// Two Pointers ; DP ; Manacher's Alg.


// My solution:
// 双指针+判断回文字符串的函数
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.c_str() == nullptr || s==string("") || s.length() == 1)
            return s;
        
        unsigned length = s.length();
        unsigned count = 0;
        string result_str;
        for(unsigned start = 0; start<length-1; start++)
            for(unsigned end = length-1; end>start && end-start+1>count; end--)
            {
                if(s[start] == s[end])
                {
                    if(isPalindromicSubstr(s, start, end))
                    {
                        count = end-start+1;
                        result_str = s.substr(start, end-start+1);
                    }
                }
            }
        
        if(count)
            return result_str;
        else
            return s.substr(0,1); // 若未找到回文字符串则返回第一个字符
    }
    
    bool isPalindromicSubstr(string& s, int start, int end)
    {
        if(start>end)
            return false;
        while(start<end)
        {
            if(s[start] == s[end])
            {
                start++;
                end--;
            }
            else
                return false;
        }
        
        return true;
    }
};


// DP
// dp[i][j]表示字符串区间[i, j]是否为回文串，当i=j时，只有一个字符，肯定是回文串，
// 若i=j+1，说明是相邻字符，此时需要判断s[i]是否等于s[j]，如果i和j不相邻，即i-j >= 2时，
// 除了判断s[i]和s[j]相等之外，dp[j + 1][i - 1]若为真，就是回文串。
// 递推公式：
// dp[i, j] = 1  								(if i == j)
// dp[i, j] = s[i] == s[j]  					(if j = i + 1)
// dp[i, j] = s[i] == s[j] && dp[i + 1][j - 1]  (if j > i + 1)

class Solution {
public:
    string longestPalindrome(string s) {
        int dp[s.size()][s.size()] = {0}, left = 0, right = 0, len = 0;
        for (int i = 0; i < s.size(); ++i) 
        {
            for (int j = 0; j < i; ++j) 
            {
                dp[j][i] = (s[i] == s[j] && (i - j < 2 || dp[j + 1][i - 1]));
                if (dp[j][i] && len < i - j + 1) 
                {
                    len = i - j + 1;
                    left = j;
                    right = i;
                }
            }
            dp[i][i] = 1;
        }
        return s.substr(left, right - left + 1);
    }
};


// 马拉车算法Manacher's Algorithm
class Solution {
public:
    string longestPalindrome(string s) {
        string t ="$#";
        for (int i = 0; i < s.size(); ++i) {
            t += s[i];
            t += '#';
        }
        int p[t.size()] = {0}, id = 0, mx = 0, resId = 0, resMx = 0;
        for (int i = 0; i < t.size(); ++i) {
            p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;
            while (t[i + p[i]] == t[i - p[i]]) ++p[i];
            if (mx < i + p[i]) {
                mx = i + p[i];
                id = i;
            }
            if (resMx < p[i]) {
                resMx = p[i];
                resId = i;
            }
        }
        return s.substr((resId - resMx) / 2, resMx - 1);
    }
};

// Testing cases:
// ""
// "a"
// "abcd"  output: "a"
// "babadada" output: "adada"