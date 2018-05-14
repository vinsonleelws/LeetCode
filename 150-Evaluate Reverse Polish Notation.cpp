Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Note:

    Division between two integers should truncate toward zero.
    The given RPN expression is always valid. That means the expression would always evaluate to a result and there won't be any divide by zero operation.

Example 1:

Input: ["2", "1", "+", "3", "*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9

Example 2:

Input: ["4", "13", "5", "/", "+"]
Output: 6
Explanation: (4 + (13 / 5)) = 6

Example 3:

Input: ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
Output: 22
Explanation: 
  ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22

// Stack or Recursion

// #1
// 使用栈
// 从前往后遍历数组，遇到数字则压入栈中，遇到符号，则把栈顶的两个数字拿出来运算，把结果再压入栈中，直到遍历完整个数组，栈顶数字即为最终答案。
class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        if (tokens.size() == 1) 
            return atoi(tokens[0].c_str());
        stack<int> s;
        for (int i = 0; i < tokens.size(); ++i) 
        {
            if (tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/") 
                s.push(atoi(tokens[i].c_str()));
            else 
            {
                int m = s.top();
                s.pop();
                int n = s.top();
                s.pop();
                if (tokens[i] == "+") s.push(n + m);
                if (tokens[i] == "-") s.push(n - m);
                if (tokens[i] == "*") s.push(n * m);
                if (tokens[i] == "/") s.push(n / m);
            }
        }
        return s.top();
    }
};

// #2
// 使用递归
// 由于一个有效的逆波兰表达式的末尾必定是操作符，所以我们可以从末尾开始处理，如果遇到操作符，向前两个位置调用递归函数，找出前面两个数字，然后进行操作将结果返回，如果遇到的是数字直接返回即可。
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int op = tokens.size() - 1;
        return helper(tokens, op);
    }
    int helper(vector<string>& tokens, int& op) {
        string s = tokens[op];
        if (s == "+" || s == "-" || s == "*" || s == "/") 
        {
            int v2 = helper(tokens, --op);
            int v1 = helper(tokens, --op);
            if (s == "+") 
                return v1 + v2;
            else if (s == "-") 
                return v1 - v2;
            else if (s == "*") 
                return v1 * v2;
            else return 
            v1 / v2;
        } 
        else 
            return stoi(s); // int stoi (const string&  str, size_t* idx = 0, int base = 10); // <string>
    }
};