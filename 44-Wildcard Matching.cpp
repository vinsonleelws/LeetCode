Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

Note:

    s could be empty and contains only lowercase letters a-z.
    p could be empty and contains only lowercase letters a-z, and characters like ? or *.

Example 1:

Input:
s = "aa"
p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".

Example 2:

Input:
s = "aa"
p = "*"
Output: true
Explanation: '*' matches any sequence.

Example 3:

Input:
s = "cb"
p = "?a"
Output: false
Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.

Example 4:

Input:
s = "adceb"
p = "*a*b"
Output: true
Explanation: The first '*' matches the empty sequence, while the second '*' matches the substring "dce".

Example 5:

Input:
s = "acdcb"
p = "a*c?b"
Output: false

// Reference solution: 
// 思路：
// 基于贪婪算法Greedy Alogrithm来解，由于有特殊字符*和？，其中？能代替任何字符，*能代替任何字符串，
// 那么我们需要定义几个额外的指针，其中scur和pcur分别指向当前遍历到的字符，
// 再定义pstar指向p中最后一个*的位置，sstar指向此时对应的s的位置，具体算法如下：
// - 定义scur, pcur, sstar, pstar
// - 如果*scur存在
  // - 如果*scur等于*pcur或者*pcur为 '?'，则scur和pcur都自增1
  // - 如果*pcur为'*'，则pstar指向pcur位置，pcur自增1，且sstar指向scur
  // - 如果pstar存在，则pcur指向pstar的下一个位置，scur指向sstar自增1后的位置
// - 如果pcur为'*'，则pcur自增1
// - 若*pcur存在，返回False，若不存在，返回True

class Solution {
public:
    bool isMatch(string s, string p) {
        int scur = 0, pcur = 0, sstar = 0, pstar = -1;
        while(scur<s.length()) {
            if(pcur<p.length() && (s[scur] == p[pcur] || p[pcur] == '?')) {
                ++scur;
                ++pcur;
            }else if(pcur<p.length() && p[pcur] == '*') {
                pstar = pcur++;
                sstar = scur;
            }else if(pstar!=-1) {
                pcur = pstar+1;
                scur = ++sstar;
            }else return false;
        } 
        while(pcur<p.length() && p[pcur] == '*') 
            ++pcur;
        
        return pcur == p.length();
    }
};

// Reference solution:
// 基于动态规划的算法：
// 用dp[i][j]表示字符串s,p分别匹配到位置i,j时是否匹配
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for (int i = 1; i <= n; ++i) {
            if (p[i - 1] == '*') dp[0][i] = dp[0][i - 1];
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] == '*') {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                } else {
                    dp[i][j] = (s[i - 1] == p[j - 1] || p[j - 1] == '?') && dp[i - 1][j - 1];
                }
            }
        }
        return dp[m][n];
    }
};


// My solution: 基于递归的解法，会超时... [Time Limit Exceeded]
class Solution {
public:
    bool isMatch(string s, string p) {
        if(!s.empty() && p.empty())
            return false;
        
        if(s[s.length()-1]!=p[p.length()-1] && p[p.length()-1]!='*' && p[p.length()-1]!='?')
            return false;
        
        return match(s, p, 0, 0);
    }
    
    bool match(string s, string p, int i, int j)
    {
        if(j==p.length()-1 && p[j] =='*')
            return true;
        
        if(i==s.length() && j==p.length())
            return true;
        
        if(i<s.length() && j==p.length())
            return false;
        
        if(i==s.length() && j<p.length())
        {
            while(j<p.length() && p[j]=='*')
                j++;
            if(j<p.length())
                return false;
            else
                return true;
        }
        
        if(s[i] == p[j] || p[j]=='?')
            return match(s, p, i+1, j+1);
        else
        {
            if(p[j]=='*')
            {
                while(j+1<p.length()&&p[j+1]=='*')
                    j++;
                if(j==p.length()-1)
                    return true;
                else
                    return match(s, p, i, j+1) || match(s, p, i+1, j);
            }
            else
                return false;
        }
        
    }
};


// "ho"
// "ho**"
// true

// "aaabbbaabaaaaababaabaaabbabbbbbbbbaabababbabbbaaaaba"
// "a*******b"
// false

// "babbbbaabababaabbababaababaabbaabababbaaababbababaaaaaabbabaaaabababbabbababbbaaaababbbabbbbbbbbbbaabbb"
// "b**bb**a**bba*b**a*bbb**aba***babbb*aa****aabb*bbb***a"
// false

// "abbabaaabbabbaababbabbbbbabbbabbbabaaaaababababbbabababaabbababaabbbbbbaaaabababbbaabbbbaabbbbababababbaabbaababaabbbababababbbbaaabbbbbabaaaabbababbbbaababaabbababbbbbababbbabaaaaaaaabbbbbaabaaababaaaabb"
// "**aa*****ba*a*bb**aa*ab****a*aaaaaa***a*aaaa**bbabb*b*b**aaaaaaaaa*a********ba*bbb***a*ba*bb*bb**a*b*bb"
// false