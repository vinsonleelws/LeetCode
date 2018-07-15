/*Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

Example 1:

Input: num1 = "2", num2 = "3"
Output: "6"

Example 2:

Input: num1 = "123", num2 = "456"
Output: "56088"

Note:

    The length of both num1 and num2 is < 110.
    Both num1 and num2 contain only digits 0-9.
    Both num1 and num2 do not contain any leading zero, except the number 0 itself.
    You must not use any built-in BigInteger library or convert the inputs to integer directly.
    */

class Solution {
public:
    string multiply(string num1, string num2) {

    }
};

// 字符串相乘
// Math ; 错位相乘相加法

// 基于多位数的乘法过程，每位相乘然后错位相加，把错位相加后的结果保存到一个一维数组中，
// 然后分别每位上算进位，最后每个数字都变成一位，然后要做的是去除掉首位0，最后把每位上的数字按顺序保存到结果中即可.

// My solution:
class Solution {
public:
    string multiply(string num1, string num2) {
        int n1 = num1.size();
        int n2 = num2.size();
        if (n1 == 0)
            return num2;
        else if (n2 == 0)
            return num1;

        vector<int> m(n1 + n2, 0); // 最终结果位数不会超过n1+n2
        int last = n1 + n2 - 1;

        for (int i = 0; i < n1; i++)
            for (int j = 0; j < n2; j++)
                m[i + j + 1] += (num1[i] - '0') * (num2[j] - '0'); //m[0] is the highest position.

        int carry = 0;
        for (int i = last; i >= 0; i--)
        {
            m[i] += carry;
            carry = m[i] / 10;
            m[i] = m[i] % 10;
        }

        string result;
        int i = 0;
        while (i <= last && m[i] == 0)  // 去除开头多余的0
            i++;
        if (i > last)
            return "0";
        for (; i <= last; i++)
            result.push_back(m[i] + '0'); //'+' instead of '-'

        return result;

    }
};

//  Testing cases:
//  "0"
//  "0"