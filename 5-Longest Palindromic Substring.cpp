Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.

Example 2:

Input: "cbbd"
Output: "bb"

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

// Testing cases:
// ""
// "a"
// "abcd"  output: "a"
// "babadada" output: "adada"