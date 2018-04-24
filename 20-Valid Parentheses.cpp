Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

    1. Open brackets must be closed by the same type of brackets.
    2. Open brackets must be closed in the correct order.

Note that an empty string is also considered valid.

Example 1:

Input: "()"
Output: true

Example 2:

Input: "()[]{}"
Output: true

Example 3:

Input: "(]"
Output: false

Example 4:

Input: "([)]"
Output: false

Example 5:

Input: "{[]}"
Output: true

class Solution {
public:
    bool isValid(string s) {
        if(s == "")
            return true;
        
        stack<char> brackets;
        int i=0;
        while(i<s.length())
        {
            if(s[i]=='('||s[i]=='{'||s[i]=='[')
                brackets.push(s[i++]);
            else if(brackets.size())
            {
                if(s[i]==')')
                {
                    if(brackets.top() != '(')
                        return false;            
                }
                else if(s[i]=='}')
                {
                    if(brackets.top() != '{')
                        return false;   
                }
                else if(s[i]==']')
                {
                    if(brackets.top() != '[')
                        return false;   
                }
                
                brackets.pop();
                i++;
            }
            else 
                return false;
        }
        
        if(brackets.empty())
            return true;
        else
            return false;
    }
};

// Testing cases
// "{[]}{}{()}"
// true

// Input: "([)"
// Expected: false

// Input: "(([]){})"
// Expected: true
