Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

Example 1:

Input: "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()"

Example 2:

Input: ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()"


// 思路：使用一个栈模拟括号的配对，栈中记录的是左括号的位置'('，使用一个变量start记录当前配对起始位置。
// 当字符是'('时，直接入栈; 当字符是')'时，若栈为空，则更新start为下一个字符的位置
// 若栈不为空，取出栈顶元素。更新长度：result = bstack.empty()? max(result, i-start+1):max(result, i-bstack.top());

class Solution {
public:
    int longestValidParentheses(string s) {
        int result = 0, start = 0;
        stack<int> bstack;
        for(int i = 0; i < s.size(); ++i) 
        {
            if (s[i] == '(') 
                bstack.push(i);
            else if (s[i] == ')') 
            {
                if (bstack.empty()) 
                    start = i + 1;
                else 
                {
                    bstack.pop();
                    result = bstack.empty() ? max(result, i - start + 1) : max(result, i - bstack.top());
                }
            }
        }
        return result;
    }
};

// Reference solution:
// 栈模拟
class Solution {
public:
    int longestValidParentheses(string s) {
        int res = 0, start = 0;
        stack<int> m;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') m.push(i);
            else if (s[i] == ')') {
                if (m.empty()) start = i + 1;
                else {
                    m.pop();
                    res = m.empty() ? max(res, i - start + 1) : max(res, i - m.top());
                }
            }
        }
        return res;
    }
};


// Input: "()(()"
// Expected: 2

// Input: "(()"
// Expected: 2

// Input: ")()())()()("
// Expected: 4

// Input: ")(((((()())()()))()(()))("
// Expected: 22