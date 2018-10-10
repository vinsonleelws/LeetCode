/*Implement a basic calculator to evaluate a simple expression string.

The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate toward zero.

Example 1:

Input: "3+2*2"
Output: 7

Example 2:

Input: " 3/2 "
Output: 1

Example 3:

Input: " 3+5 / 2 "
Output: 5

Note:

    You may assume that the given expression is always valid.
    Do not use the eval built-in library function.*/

class Solution {
public:
    int calculate(string s) {
        
    }
};

//  基本计算器II（包含+-*/，正数和空格）
//  Stack

// My solution:
class Solution {
public:
    int calculate(string s) {
        int result = 0;
        int n = s.length();
        int num = 0;
        stack<int> st;
        bool negative = false;
        for (int i = 0; i < n; i++)
        {
            if (s[i] >= '0')
                num = num * 10 + s[i] - '0';
            else if (s[i] == '*' || s[i] == '/')
            {
                int right  = 0;
                char op = s[i];
                while (++i < n)
                {
                    if (s[i] == ' ')
                        continue;
                    if (s[i] >= '0')
                        right = right * 10 + s[i] - '0';
                    else
                        break;
                }
                i--;
                num = (op == '*') ? num * right : num / right;
            }
            else if (s[i] == '+' || s[i] == '-')
            {
                if (negative)
                    st.push(-num);
                else
                    st.push(num);
                num = 0;
                negative = (s[i] == '-') ? true : false;
            }
            else
                continue;
        }

        result = negative ? -num : num;
        while (st.size())
        {
            result += st.top();
            st.pop();
        }

        return result;
    }
};

// Other reference solutions:
// #1
class Solution {
public:
    int calculate(string s) {
        int res = 0, num = 0, n = s.size();
        char op = '+';
        stack<int> st;
        for (int i = 0; i < n; ++i) {
            if (s[i] >= '0') {
                num = num * 10 + s[i] - '0';
            }
            if ((s[i] < '0' && s[i] != ' ') || i == n - 1) {
                if (op == '+') st.push(num);
                if (op == '-') st.push(-num);
                if (op == '*' || op == '/') {
                    int tmp = (op == '*') ? st.top() * num : st.top() / num;
                    st.pop();
                    st.push(tmp);
                }
                op = s[i];
                num = 0;
            }
        }
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        return res;
    }
};

// #2
class Solution {
public:
    int calculate(string s) {
        int res = 0, curRes = 0, num = 0, n = s.size();
        char op = '+';
        for (int i = 0; i < n; ++i) {
            char c = s[i];
            if (c >= '0' && c <= '9') {
                num = num * 10 + c - '0';
            }
            if (c == '+' || c == '-' || c == '*' || c == '/' || i == n - 1) {
                switch (op) {
                case '+': curRes += num; break;
                case '-': curRes -= num; break;
                case '*': curRes *= num; break;
                case '/': curRes /= num; break;
                }
                if (c == '+' || c == '-' || i == n - 1) {
                    res += curRes;
                    curRes = 0;
                }
                op = c;
                num = 0;
            }
        }
        return res;
    }
};