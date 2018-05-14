Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
    ...

Example 1:

Input: 1
Output: "A"

Example 2:

Input: 28
Output: "AB"

Example 3:

Input: 701
Output: "ZY"

// 10进制转26进制

// 递归只需一句话...
// Recursion
class Solution {
public:
    string convertToTitle(int n) {
        return n == 0 ? "" : convertToTitle(n / 26) + (char)(--n % 26 + 'A');
    }
};


// Non-recursion
class Solution {
public:
    string convertToTitle(int n) {
        string res;
        while (n) {
            res += --n % 26 + 'A';
            n /= 26;
        }
        return string(res.rbegin(), res.rend());
    }
};


// My solution: Runtime beats 100% of cpp submissions. 
class Solution {
public:
    string convertToTitle(int n) {
        string result;
        map<int, char> m;
        for(int i=1; i<=26; i++)
            m[i] = i-1+'A';
        
        int q = n/26;
        int rem = n%26;
        if(rem>0)
            result = m[rem];
        else
        {
            result = 'Z';
            q--;
        }
        
        while(q)
        {
            if(q<26)
            {
                result = m[q%26] + result;
                return result;
            }
            else
            {
                rem = q%26;
                if(rem>0)
                    result = m[rem] + result;
                else 
                {
                    result = 'Z' + result;
                    q--;
                }
                q /= 26;
            }
        }
        
        return result;
    }
};




