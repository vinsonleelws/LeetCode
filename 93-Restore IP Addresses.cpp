/*Given a string containing only digits, restore it by returning all possible valid IP address combinations.

Example:

Input: "25525511135"
Output: ["255.255.11.135", "255.255.111.35"]
*/


class Solution {
public:
    vector<string> restoreIpAddresses(string s) {

    }
};


// 构建所有可能的IP地址  [M]
// DFS (Backtracking)

// Reference solution:
// 基于回溯法
// 首先明确约束条件，IP地址某一段的有效值范围是：[0,255]，0可以成某一段，如果有两位或三位时，像 00， 01， 001， 011， 000等都是不合法的
// 我们总共要构成4段(由3个点的位置决定)，每构成一个段，都需检验当前的段是否合法。每个段可以取1位，2位或3位数字。

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        int n = s.length();
        vector<string> result;
        if (n < 4)
            return result;
        restoreIpAddressesBacktracking(s, 4, "", result);  // 4 : 4段字符串
        return result;
    }

    void restoreIpAddressesBacktracking(const string& s, int n, string sol, vector<string>& result)
    {
        if (n == 0)
        {
            if (s.empty())
                result.push_back(sol);
        }
        else
        {
            for (int i = 1; i <= 3; i++)
            {
                if (s.size() >= i)
                {
                    string str = s.substr(0, i);
                    int num = atoi(str.c_str());  // 将备选字符串转换为数字，便于判断
                    if (num > 255 || i >= 2 && str[0] == '0') // num>255, 及00， 01， 001， 011， 000等非法情况
                        break;
                    else
                    {
                        if (n != 1)
                            restoreIpAddressesBacktracking(s.substr(i), n - 1, sol + str + ".", result); // 对子字符串s.substr(i)进行调用
                        else
                            restoreIpAddressesBacktracking(s.substr(i), n - 1, sol + str, result);  // n == 1，最后一个子串不需加'.'
                    }

                }
            }
        }
    }
};


// 下面的写法只是将入口的判断条件改为 if(n == 0 && s.empty()), 但会造成TLE...
// 可见判断条件连写对时间效率影响还是挺大的。
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        int n = s.length();
        vector<string> result;
        if (n < 4)
            return result;
        restoreIpAddressesBacktracking(s, 4, "", result);
        return result;
    }

    void restoreIpAddressesBacktracking(const string& s, int n, string sol, vector<string>& result)
    {
        if (n == 0 && s.empty())
        {
            result.push_back(sol);
        }
        else
        {
            for (int i = 1; i <= 3; i++)
            {
                if (s.size() >= i)
                {
                    string str = s.substr(0, i);
                    int num = atoi(str.c_str());
                    if (num > 255 || i >= 2 && str[0] == '0')
                        break;
                    else
                    {
                        if (n != 1)
                            restoreIpAddressesBacktracking(s.substr(i), n - 1, sol + str + ".", result);
                        else
                            restoreIpAddressesBacktracking(s.substr(i), n - 1, sol + str, result);
                    }

                }
            }
        }
    }
};


// 另一种写法：
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        restore(s, 4, "", result);
        return result;
    }
    void restore(string s, int n, string sol, vector<string> &result) {
        if (n == 0)
        {
            if (s.empty())
                result.push_back(sol);
        }
        else {
            for (int i = 1; i <= 3; ++i)
            {
                if (s.size() >= i && isValid(s.substr(0, i)))
                {
                    if (n == 1)
                        restore(s.substr(i), n - 1, sol + s.substr(0, i), result);
                    else
                        restore(s.substr(i), n - 1, sol + s.substr(0, i) + ".", result);
                }
            }
        }
    }
    bool isValid(string s) {
        if (s.empty() || s.size() > 3 || (s.size() > 1 && s[0] == '0'))
            return false;
        int num = atoi(s.c_str());
        return num <= 255 && num >= 0;
    }
};

// Corner cases:
// "111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111"