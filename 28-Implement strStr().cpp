/*Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2

Example 2:

Input: haystack = "aaaaa", needle = "bba"
Output: -1

Clarification:

What should we return when needle is an empty string? This is a great question to ask during an interview.

For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().
*/

class Solution {
public:
    int strStr(string haystack, string needle) {
        
    }
};

// 实现strStr()函数
// Two Pointers

// My solution.
// 提升时间效率的小技巧：并不需要遍历整个haystack字符串，只需遍历到剩下的长度和子字符串相等的位置即可.
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle == "")
            return 0;
        int hlen = haystack.size();
        int nlen = needle.size();
        if(nlen>hlen)
            return -1;
        for(int i=0; i<=hlen-nlen; i++)
        {
            if(haystack[i]==needle[0])
            {
                int j=1;
                int k=i+1;
                while(needle[j] == haystack[k] && j<nlen)
                {
                    j++;
                    k++;
                }
                if(j==nlen)
                    return i;
            }
        }
        
        return -1;
    }
};


// Reference method.
// 首先遍历母字符串，我们并不需要遍历整个母字符串，而是遍历到剩下的长度和子字符串相等的位置即可，这样可以提高运算效率。
// 然后对于每一个字符，我们都遍历一遍子字符串，一个一个字符的对应比较，如果对应位置有不等的，则跳出循环，
// 如果一直都没有跳出循环，则说明子字符串出现了，则返回起始位置即可
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty()) 
            return 0;
        int m = haystack.size(), n = needle.size();
        if(m < n) 
            return -1;
        for(int i = 0; i <= m - n; ++i) {
            int j = 0;
            for(j = 0; j < n; ++j) {
                if (haystack[i + j] != needle[j]) 
                    break;
            }
            if(j == n) 
                return i;
        }
        return -1;
    }
};

// Testing cases
// Input: "mississippi"
// "issip"
// Expected: 4