Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

Note:

    s could be empty and contains only lowercase letters a-z.
    p could be empty and contains only lowercase letters a-z, and characters like . or *.

Example 1:

Input:
s = "aa"
p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".

Example 2:

Input:
s = "aa"
p = "a*"
Output: true
Explanation: '*' means zero or more of the precedeng element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".

Example 3:

Input:
s = "ab"
p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".

Example 4:

Input:
s = "aab"
p = "c*a*b"
Output: true
Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore it matches "aab".

Example 5:

Input:
s = "mississippi"
p = "mis*is*p*."
Output: false


class Solution {
public:
    bool isMatch(string s, string p) {
        assert(p[0]!='*');
        return Match(s, p, 0, 0);
    }
    
    bool Match(string& s, string& p, int i, int j)
    {
        if(i==s.length() && j==p.length())
            return true;
        else if(i>s.length() || j>p.length())
            return false;
        
        if(p[j] == '.')
        {
            if(j < p.length()-1 && p[j+1] == '*')  // ".*"
                return Match(s, p, i+1, j+2) || Match(s, p, i+1, j) || Match(s, p, i, j+2);
            else
                return Match(s, p, i+1, j+1);
        }
        
        if(s[i] == p[j])
        {
            if(j<p.length()-1 && p[j+1] == '*')
                return Match(s, p, i+1, j+2) || Match(s, p, i+1, j) || Match(s, p, i, j+2);
            return Match(s, p, i+1, j+1);
        }
        else if(j<p.length()-1 && p[j+1] == '*')
            return Match(s, p, i, j+2);
        
        return false;
            
    }
};

// Input: "aaa"
// "ab*a*c*a"
// Expected: true

// Input: "ab"
// ".*.."
// Expected: true

// 分情况讨论：".x"; ".*"; "x*" (x代表某个字母)