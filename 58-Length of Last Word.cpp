Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

Example:

Input: "Hello World"
Output: 5

// My solution:
class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s.empty())
            return 0;
        
        int len=0;
        for(int i=0; i<s.length(); i++)
        {
            if(s[i]!=' ')
            {
                if(i>0 && s[i-1]==' ')
                    len = 1;
                else
                    len++;
            }
        }
        return len;
    }
};


// Another solution:
// 从字符串末尾开始，先将末尾的空格都去掉，然后开始找非空格的字符的长度即可
class Solution {
public:
    int lengthOfLastWord(string s) {
        int right = s.size() - 1, res = 0;
        while (right >= 0 && s[right] == ' ') --right;
        while (right >= 0 && s[right] != ' ' ) {
            --right; 
            ++res;
        }
        return res;
    }
};

// Testing cases:
// Input: "a "
// Expected: 1